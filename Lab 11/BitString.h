#pragma once
#include <string>

class BitString {

public:

	BitString();
	BitString(std::string str);
	BitString(const BitString& b);
	~BitString();
	BitString& conjaction(const BitString& conj_bitstr) const;
	void input_func();
	void show_result();
	void FileInput(std::string filename);
	void FileOutput();
	BitString& operator=(const BitString& str);
	unsigned char& operator[](int i);
	friend BitString& operator&(const BitString& str1, const BitString& str2);
	friend std::ostream& operator<<(std::ostream& c_out, const BitString& i_str);
	friend std::istream& operator>>(std::istream& c_in, BitString& o_str);

private:

	unsigned char* bs;
	int len;
	void mas_from_string(std::string str);
	BitString& conjaction_repeat(const BitString& conj_bitstr, int l) const;
	
};

