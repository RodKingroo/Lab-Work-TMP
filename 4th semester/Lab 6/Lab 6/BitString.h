#pragma once

#include <string>

using namespace std;

class BitString {

	unsigned char* mas;
	int len;
	void mas_from_string(string str);
	BitString& conjaction_repeat(const BitString& b, int len);

public:

	BitString();
	BitString(string init_str);
	BitString(const BitString& b);
	~BitString();

	BitString& conjaction(const BitString& conj_bitstr);
	BitString& operator=(const BitString& str);

	void InputFunc();
	void ShowResult();
	void FileInput(string filename);
	void FileOutput(string filename);

	unsigned char& operator[](int i);
	unsigned char* getMas() { return mas; }

	friend BitString& operator&(BitString& a, BitString& b);
	friend ostream& operator<<(ostream& c_out, BitString& a);
	friend istream& operator>>(istream& c_out, BitString& a);

	int getLen() { return len; }
};

