#pragma once

#include <string>

using namespace std;

class BitString {

public:

	BitString();
	BitString(string str);
	BitString(const BitString& b);
	~BitString();

	BitString& conjaction(const BitString& conj_bitstr) const;
	BitString& operator=(const BitString& str);

	void InputFunc();
	void ShowResult();
	void FileInput(string filename);
	void FileOutput(string filename);

	unsigned char& operator[](int i);
	unsigned char* getMas() { return bs; }

	friend BitString& operator&(BitString& a, BitString& b);
	friend ostream& operator<<(ostream& c_out, BitString& a);
	friend istream& operator>>(istream& c_out, BitString& a);

	int getLen() { return len; }

private:

	unsigned char* bs;
	int len;
	void mas_from_string(string str);
	BitString &conjaction_repeat(const BitString& conj_bitstr, int l) const;

};

