/*

*   Please write a C++ OOP program, that contains a class that stores text lines.

*   The class should be able to:

	*   read the text lines from
			keyboard
			file

	*   print the text lines to
			screen
			file

	*   sort the lines alphabetically.

	*   using:
			string class
			STL/class library container (vector, list, queue, ...)
			<algorithm>

*   You are free to choose the classes you use. One container is sufficient.

*   add some time measurement (you need 1000s of lines to see real numbers)
	Best do measurements of the times for reading/sorting/writing separately.

*   Compare the times (Pure C string and C++ container)

*   on different platforms (e.g. your own computer, lab computer, ...)
	the classical solution of last assignment and this one

*   Please describe the results and if those fit your expectations.

*   Please submit the full sources of both solutions (classical and with string/container)
	and a short result explanation report. The report should contain the times measured
	and a statement if the result fits to your expectations and why/why not.

*   Please keep the deadline.

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "cString.h"
#include "common.h"
#include "cStrings.h"

#define _BUFFER_SIZE 1024
#define _MAX_LINES 1024
#define _QUIET


int main()
{
	using namespace std;

	// Initilization
	std::cout << std::fixed << std::setprecision(9) << std::left;

	/* read in a string from keyboard */
	cout << "**********Read a string from keyboard, sort it then write it to a file**********\nPlease Enter a string:";
	common::timer myTimer;  //  set a timer
	cString c_str(_BUFFER_SIZE);    // read in the string from keyboard
	cout << "[cString] Time for reading string from keyboard is " << myTimer.time() << " sec" << endl;
	myTimer.reset();    // reset the timer

	/* Sorting the string */
	c_str.sort_cString();
	cout << "[cString] Time for sorting the string is " << myTimer.time() << " sec" << endl;
	myTimer.reset();    // reset the timer

	/* Writing the string */
	// Write to file
	c_str.write_cString("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfilewrite.txt");
	cout << "[cString] Time for writing the string to file is " << myTimer.time() << " sec" << endl;
	// Write to console
#ifndef _QUIET
	cout << "[cString] Sorted string is: " << c_str.get_cString()->buffer << endl;
#endif // !_QUIET
	
	

	/* read in a string from file */
	cout << "\n**********Read strings from file line by line, sort the lines then write them to another file**********" << endl;
	cString* c_str_arrayP = new cString[_MAX_LINES];	// declare a array
	FILE* fp;
	errno_t err = fopen_s(&fp, "D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfile.txt", "rb");	// open file
	if (err)
	{
		cerr << "Unable to open file!";
		delete[] c_str_arrayP;
		exit(1);
	}

	myTimer.reset();
	for (int i = 0; i < _MAX_LINES; i++)
	{
		c_str_arrayP[i].readin_line(fp, _BUFFER_SIZE);
	}
	cout << "[cString] Time for reading lines from file is " << myTimer.time() << " sec" << endl;
	fclose(fp);

	/* Sorting the string */
	myTimer.reset();
	for (int i = 0; i < _MAX_LINES; i++)
	{
		if (c_str_arrayP[i].get_cString() == nullptr)
			break;
		c_str_arrayP[i].sort_cString();
	}
	cout << "[cString] Time for sorting the string is " << myTimer.time() << " sec" << endl;

	/* Writing the string */
	// write to file
	myTimer.reset();
	for (int i = 0; i < _MAX_LINES; i++)
	{
		if (c_str_arrayP[i].get_cString() == nullptr)
			break;
		c_str_arrayP[i].write_cString("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfilewrite.txt");
	}
	cout << "[cString] Time for writing the string to file is " << myTimer.time() << " sec" << endl;
	// write to console
#ifndef _QUIET
	cout << "[cString] Sorted string is:";
		for (int i = 0; i < _MAX_LINES; i++)
		{
			if (c_str_arrayP[i].get_cString() == nullptr)
				break;
			cout << c_str_arrayP[i].get_cString()->buffer;
		}
#endif // !_QUIET
	
		cout << "\n**********Read in lines from files, sort lines seperately then write it to a file**********\n";
		myTimer.reset();
		cStrings s("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfile.txt");
		cout << "[cStrings] Time for writing the string to file is " << myTimer.time() << " sec" << endl;
		/* Sorting the lines */
		myTimer.reset();
		s.lines_sorting();
		cout << "[cStrings] Time for sorting the lines is " << myTimer.time() << " sec" << endl;
		myTimer.reset();
		s.write_cStrings("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfilewrite.txt");
		cout << "[cStrings] Time for writing the lines into files is " << myTimer.time() << " sec" << endl;
#ifndef _QUIET
		s.print_Strings();
#endif // !_QUIET

	
	
	// inputString is for user keyboard input
	// tmpString is for reading in from file later use
	string inputString, tmpString;
	// A vector storing all files, because read by line
	vector<string> inputStringVector;

	/* read in a string from keyboard */
	cout << "\n**********Read a string from keyboard, sort it then write it to a file**********\nPlease Enter a string:";
	myTimer.reset();			 // reset the timer
	getline(cin, inputString);   //  read in from keyboard (terminal)
	cout << "[STL] Time for reading string from keyboard is " << myTimer.time() << " sec" << endl;

	/* Sorting the string */
	myTimer.reset();			 // reset the timer
	sort(inputString.begin(), inputString.end());
	cout << "[STL] Time for sorting the string is " << myTimer.time() << " sec" << endl;
	
	/* Writing the string */
	// write to file
	ofstream fp_stl;
	fp_stl.open("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfilewrite.txt", ios::in | ios::binary);
	if (!fp_stl.is_open())
	{
		cerr << "Error open file!";
		exit(0);
	}
	myTimer.reset();    // reset the timer
	fp_stl << inputString;
	cout << "[STL] Time for writing the string to file is " << myTimer.time() << " sec" << endl;
#ifndef _QUIET
	cout << "[STL] Sorted string is: " << inputString << endl;
#endif // !_QUIET
	
	fp_stl.close();
	
	/* read in a string from file */
	cout << "\n**********Read strings from file line by line, sort the lines then write them to another file**********" << endl;
	ifstream myfile("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfile.txt", ios::out | ios::app | ios::binary);
	if (!myfile.is_open())
	{
		cerr << "Error open file!";
		exit(0);
	}
	myTimer.reset();    // reset the timer
	for (int i = 0; i < _MAX_LINES; i++)
	{
		if(getline(myfile, tmpString))
			inputStringVector.push_back(tmpString);
	}
	cout << "[STL] Time for reading lines from file is " << myTimer.time() << " sec" << endl;
	myfile.close();

	/* Sorting the string */
	myTimer.reset();
	for (vector<string>::iterator iter = inputStringVector.begin(); iter != inputStringVector.end(); iter++)
	{
		sort((*iter).begin(), (*iter).end());
	}
	cout << "[STL] Time for sorting the string is " << myTimer.time() << " sec" << endl;

	/* Writing the string */
	// write to file
	ofstream fileOutput;
	fileOutput.open("D:\\Documents\\GitHub\\Warmup_Advancedprog\\task2\\test\\testfilewrite.txt", ios::out | ios::binary | ios::app);
	if (!fileOutput.is_open())
	{
		cerr << "Error open file!";
		exit(0);
	}
	myTimer.reset();
	for (vector<string>::iterator iter = inputStringVector.begin(); iter != inputStringVector.end(); iter++)
	{
		fileOutput << *iter;
	}
	cout << "[STL] Time for writing the string to file is " << myTimer.time() << " sec" << endl;
	// write to console
#ifndef _QUIET
	cout << "[cString] Sorted string is:";
		for (vector<string>::iterator iter = inputStringVector.begin(); iter != inputStringVector.end(); iter++)
		{
			cout << *iter << endl;
		}
#endif // !_QUIET
	
	fileOutput.close();
	

	return 0;
}