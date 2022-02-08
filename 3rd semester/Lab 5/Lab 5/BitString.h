#pragma once
#include <string>

using namespace std;

class BitString
{

	unsigned char bs[8];

public:
	BitString();
	BitString(string inp_string);
	
	void input();
	void output();

	void FileInput(string filename);
	void FileOutput(string filename);

	BitString conjaction(BitString b);

};

