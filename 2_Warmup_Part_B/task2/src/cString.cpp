#include "cString.h"
cString::cString() {
	this->p = NULL;
}
cString::cString(size_t buffer_size)
{
	this->p = zero_str(buffer_size);
	if (!fgets(this->p->buffer, buffer_size, stdin))
	{
		throw "Error reading string!";
	}
	
	rmv_eol(&(this->p));
	chk_str(&(this->p));
}
cString::cString(const char* string) 
{
	this->p = new_str(string);
}

cString::cString(const char* filename, bool lineByline, size_t lineIndex)
{
	if (!lineByline)
	{
		FILE* fp;
		errno_t err;
		err = fopen_s(&fp, filename, "rb");
		if (err)
		{
			throw "Unable to open file!";
		}
		this->p = readin_file_str(fp);
		if (!this->p)
		{
			fclose(fp);
			throw "Unable to read file!";
		}
		else
		{
			fclose(fp);
		}
	}
	else
	{
		FILE* fp;
		errno_t err;
		err = fopen_s(&fp, filename, "rb");
		if (err)
		{
			throw "Unable to open file!";
		}

		for (size_t i = 1; i < lineIndex; i++)
		{
			if (!moveToNextLine(fp))
			{
				throw "Invalid index!";
			}
		}
		
		char ch;
		fpos_t position_start, position_end;
		fgetpos(fp, &position_start);
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF || ch == '\n')
				break;
		}
		fgetpos(fp, &position_end);
		size_t size = position_end - position_start;
		fsetpos(fp, &position_start);

		this->p = zero_str(size);
		fgets(this->p->buffer,this->p->size,fp);

		rmv_eol(&(this->p));
		chk_str(&(this->p));

		fclose(fp);
	}
}

cString::cString(FILE* fp, bool lineByline, size_t lineIndex)
{
	if (!lineByline)
	{
		this->p = readin_file_str(fp);
		if (!this->p)
		{
			throw "Unable to read file!";
		}
	}
	else
	{
		for (size_t i = 1; i < lineIndex; i++)
		{
			if (!moveToNextLine(fp))
			{
				throw "Invalid index!";
			}
		}

		char ch;
		fpos_t position_start, position_end;
		fgetpos(fp, &position_start);
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF || ch == '\n')
				break;
		}
		fgetpos(fp, &position_end);
		size_t size = position_end - position_start + 1;
		fsetpos(fp, &position_start);

		this->p = zero_str(size);
		fgets(this->p->buffer, this->p->size, fp);

		rmv_eol(&(this->p));
		chk_str(&(this->p));
	}
}

cString::cString(str_p p) {
	this->p = cpy_str(p);
}

cString::~cString() {
	free_str(this->p);
	this->p = nullptr;
}

str_p cString::get_cString(void) {
	return this->p;
}

bool  cString::is_nullstr(void) {
	if (this->p)
	{
		if (this->p->buffer) {
			return false;
		}
	}
	return true;
}

void cString::print_cString(void)
{
	if (!is_nullstr())
	{
		cout << this->p->buffer;
	}
}

void cString::sort_cString(void)
{
	chk_str(&this->p);
	sort_str(this->p);
}

void cString::write_cString(const char* filename)
{
	FILE* fp;
	errno_t err;
	err = fopen_s(&fp, filename, "ab");
	if (err)
	{
		throw "Unable to open file!";
	}
	if (write2_file_str(fp, this->p))
	{
		fclose(fp);
		throw "Unable to write file!";
	}
	fclose(fp);
}

bool cString::readin_line(FILE* fp, size_t buffer_size)
{
	if (!feof(fp))
	{
		if (is_nullstr())
			free_str(this->p);
		this->p = zero_str(buffer_size);
		if (!fgets(this->p->buffer, buffer_size, fp))	// add \0 automatically
			return false;
		return true;
	}
	return false;
}

bool moveToNextLine(FILE* fp)
{
	char c;
	while (1)
	{
		c = fgetc(fp);
		if (c == EOF) 
			return false;
		if (c == '\n') break;
	}

	return true;
}