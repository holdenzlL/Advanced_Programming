#pragma once
#include "cString.h"
#ifdef _CSTR_VERSION_1_0
#define _CSTRS_VERSION_1_0
class cStrings
{
public:
	cStrings(size_t size);
	cStrings(const char *filename); // Read in file line by line, each line is stored in one cString
	~cStrings();
	void print_Strings();
	void swap_lines(size_t index_a, size_t index_b);
	void lines_sorting();
	void write_cStrings(const char *filename);

private:
	cString **p;
	size_t size;
	size_t partition(size_t low, size_t high);
	void quickSort(size_t low, size_t high);
};

#endif // _CSTR_VERSION_1_0