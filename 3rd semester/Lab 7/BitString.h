#pragma once
#include <string>

using namespace std;

class BitString
{

	unsigned char* bs;
	int len;
	void mas_from_string(string str);
	BitString conjaction_r(BitString b, int l);

public:
	BitString();
	BitString(string inp_string);

	void input();
	void output();

	void FileInput(string filename);
	void FileOutput(string filename);

	BitString conjaction(BitString b);

	BitString(const BitString &b);
	~BitString();

};

