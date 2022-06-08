#pragma once
#include "str.h"
#include <iostream>
using namespace std;

#ifdef _STR_VERSION_1_1
#define _CSTR_VERSION_1_0

class cString
{
public:
	
	cString();
	cString(size_t buffer_size);	// read the text lines from keyboard
	cString(const char* string);	
	cString(const char* filename, bool lineByline, size_t lineIndex = 0);	// read the text lines from file, if lineByline is true, then read certain line from file, which is specified by lineIndex
	cString(FILE* fp, bool lineByline, size_t lineIndex = 0);
	cString(str_p p);
	~cString();

	str_p get_cString(void);	// return the private str_p
	bool is_nullstr(void);		// judge if the str_p is nullptr, also judge the str_p->buffer
	void print_cString(void);	// print the 
	void sort_cString(void);	// sorting via quick sort
	void write_cString(const char* filename);
	bool readin_line(FILE* fp, size_t buffer_size);	//return false if encounter EOF


private:
	str_p p;			// The ending of every string should be \0
	
};

bool moveToNextLine(FILE* fp);	// it trust the input fp! if successfully jump to the next line, then reture true, if EOF, return false.

#endif // _STR_VERSION_1_1