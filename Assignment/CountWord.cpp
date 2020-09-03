﻿#include <sstream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <assert.h>
#include <complex>
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


int main(void) {
	
	

	return 0;
}
#include "MyString.h"

#define MAP map<string, int>

void Input(fstream &f, MAP &a) {
	string word;
	string total_word;
	while(f.good()) {
		while (getline(f, word)) {
			total_word += word + " ";
		}
	}
	stringstream os(total_word);
	while (os >> word) {
		a[word]++;
	}
	
}

struct Word {
	string word;
	int count;
};

void CheckNewWorld(string word, vector<Word> &a) {
	for (int i = 0; i < a.size(); ++i) {
		if (word == a[i].word) {
			a[i].count++;
			return;
		}
	}
	Word newWord;
	newWord.word = word;
	newWord.count = 1;
	a.push_back(newWord);
}

void Input_(fstream& f, vector<Word>& a) {
	char ch;
	string word = "";

		while (f.get(ch)) {
			if (isalpha(ch)) {
				word += ch;
			}
			else {
				CheckNewWorld(word, a);
				word = "";
			}
		}
	
		/// nếu mà cái điều kiện if đầu tiên mà cứ đúng hoài thì sẽ không tạo ra được ký tự khác nên phải xét tiếp
		CheckNewWorld(word, a);
		word = "";
}

int main(void) {
	fstream fin("C:/Users/Administrator/source/repos/Assignment/Assignment/Input.txt", ios_base::in);
	if (fin.fail()) {
		cout << "Occurred error when attemping open the file. Please try again."; return 0;
	}
	MAP a;
	Input(fin, a);
	for (auto x : a) {
		cout << x.first << "  " << x.second << endl;
	}
	cout << "Another way to implement!" << endl;
	vector<Word> b;
	Input_(fin, b);
	for (int i = 0; i < b.size(); ++i) {
		cout << b[i].word << ": " << b[i].count << endl;
	}
	
	return 0;
}
