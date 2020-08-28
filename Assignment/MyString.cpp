#include "MyString.h"

MyString operator+(const char* lhs, MyString rhs) {
	MyString ans(lhs);
	MyString result;
	result = ans +rhs;
	return result;
}

MyString operator+(MyString lhs, MyString rhs) {
	MyString result;
	result.name = lhs.name + rhs.name;
	return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& obj) {
	return os << obj.name;
}

MyString::MyString(const char* str) {
	name = str;
}

MyString::MyString(char str) {
	name = str;
}

MyString::MyString(string str) {
	name = str;
}

MyString& MyString::operator=(MyString mystring) {
	name = mystring.name;
	return *this;
}

 vector<MyString> MyString::Split(vector<char> arr, bool Empty) {
	vector<MyString> a;
	int n = name.size();
	int m = arr.size();
	
	if (!Empty) {
		vector<bool> clear(n, false);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (name[i] == arr[j]) clear[i] = true;
			}
		}
		string cat = "";
		for (int i = 0; i < n; ++i) {
			if (clear[i] == false) {
				cat += name[i];
				continue;
			}
			else if (clear[i] == true) {
				MyString result(cat);
				a.push_back(result);
				cat = "";
			}
		}
		return a;
	}
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (name[i] == arr[j]) name[i] = ' ';
			}
		}
		string result;
		for (int i = 0; i < n-1; ++i) {
			
			if (name[i] != ' ' && name[i+1] != ' ') {
				result += name[i];
				continue;
			}
			else if (name[i] != ' ' && name[i+1] == ' ') {
				result += name[i];
				MyString answer(result);
				a.push_back(answer);
				result = "";
			}
		}
		return a;
	}
}