#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <ostream>
#include <map>
#include <fstream>
using namespace std;


class MyString
{
	string name;
public:

	MyString() = default;
	MyString(const char* str);
	MyString(char str);
	MyString(string str);
	MyString& operator=(MyString mystring);
	friend MyString operator+ (const char* lhs, MyString rhs);
	friend MyString operator+(MyString lhs, MyString rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& obj);
	vector<MyString> Split(vector<char> arr, bool notEmpty);

};



