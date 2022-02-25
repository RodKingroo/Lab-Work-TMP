#pragma once
#include <string>

using namespace std;

class BitString {

public:

	BitString();
	BitString(std::string str);
	BitString(const BitString& b);
	~BitString();

	BitString& conjaction(const BitString& conj_bitstr) const;
	BitString& operator=(const BitString& str);

	void input_func();
	void show_result();
	void FileInput(std::string filename);
	void FileOutput();


	unsigned char& operator[](int i);
	unsigned char* getMas() { return bs; }

	friend BitString& operator&(const BitString& str1, const BitString& str2);
	friend ostream& operator<<(ostream& c_out, const BitString& i_str);
	friend istream& operator>>(istream& c_in, BitString& o_str);

	int getLen() { return len; }

private:

	unsigned char* bs;
	int len;
	void mas_from_string(string str);
	BitString &conjaction_repeat(const BitString& conj_bitstr, int l) const;

};

