#include "cStrings.h"
cStrings::cStrings(size_t size)
{
	this->size = size;
	this->p = new cString * [size];
}
cStrings::cStrings(const char* filename)
{
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, filename, "rb");
	if (err)
	{
		throw "Unable to open file!";
	}
	// how many lines does the file have?
	char ch;
	this->size = 1;	//THe line with EOF is a seperated line
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n')
		{
			this->size++;
		}
	}
	this->p = new cString * [this->size];
	rewind(fp);
	str_p tmp = NULL;
	fpos_t position_start, position_end;
	for (size_t i = 0; i < this->size; i++)
	{
		fgetpos(fp, &position_start);
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF || ch == '\n')
				break;
		}
		fgetpos(fp, &position_end);
		size_t _size = position_end - position_start + 1;
		fsetpos(fp, &position_start);

		tmp = zero_str(_size);
		fgets(tmp->buffer, tmp->size, fp);

		rmv_eol(&(tmp));
		chk_str(&(tmp));
		this->p[i] = new cString(tmp);
		free_str(tmp);
		tmp = nullptr;
	}
	fclose(fp);
}
cStrings::~cStrings()
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->p[i])
		{
			if (!((this->p[i])->is_nullstr()))
			{
				delete this->p[i];
				this->p[i] = nullptr;
			}
		}
	}
	delete[] this->p;
	this->p = nullptr;
}
void cStrings::print_Strings()
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->p[i]->print_cString();
		putchar('\n');
	}
}
void cStrings::swap_lines(size_t index_a, size_t index_b)
{
	if (!(index_a <= this->size - 1 && index_b <= this->size - 1))
	{
		throw "Invalid index!";
	}
	str_p tmp = cpy_str(this->p[index_a]->get_cString());
	delete this->p[index_a];
	this->p[index_a] = new cString(this->p[index_b]->get_cString()->buffer);
	delete this->p[index_b];
	this->p[index_b] = new cString(tmp);
	free_str(tmp);
}

size_t cStrings::partition(size_t low, size_t high)
{
	str_p pivot = new_str(this->p[low]->get_cString()->buffer);
	
	for (;;) {
		while (low < high && (strcmp(pivot->buffer, this->p[high]->get_cString()->buffer) <= 0)) {
			high--;
		}
		if (low >= high) break;
		swap_lines(low++, high);

		while (low < high && (strcmp(this->p[low]->get_cString()->buffer, pivot->buffer) <= 0)) {
			low++;
		}
		if (low >= high) break;
		swap_lines(high--, low);
	}

	delete this->p[high];
	this->p[high] = new cString(pivot);
	free_str(pivot);
	return high;
}

void cStrings::quickSort(size_t low, size_t high)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(low, high);
		if (pi)
		{
			quickSort(low, (pi - 1));
		}
		quickSort((pi + 1), high);
	}
}
void cStrings::lines_sorting()
{
	this->quickSort(0, this->size - 1);
}
void cStrings::write_cStrings(const char* filename)
{
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, filename, "ab");
	if (err)
	{
		throw "Unable to open file!";
	}
	for (size_t i = 0; i < this->size; i++)
	{
		if (write2_file_str(fp, this->p[i]->get_cString()))
		{
			fclose(fp);
			throw "Unable to write file!";
		}
	}
	fclose(fp);
}