#include <iostream>
#include <string>
#include <fstream>
#include "BitString.h"


BitString::BitString() {

	bs = 0;
	len = 0;

}

BitString::BitString(std::string str) {

	mas_from_string(str);

}

BitString::BitString(const BitString& b) {

	len = b.len;
	bs = new unsigned char[len + 1];

	for (int i = 0; i <= len; i++) bs[i] = b.bs[i];


}

void BitString::input_func() {
	std::string str;
	getline(std::cin, str);

	if (bs) delete[] bs;

	mas_from_string(str);
}

void BitString::show_result() {

	std::cout << "Result: ";

	for (int i = 0; i < len; i++) std::cout << bs[i];

	std::cout << std::endl;

}

BitString& BitString::conjaction_repeat(const BitString& conj_bitstr, int l) const {

	int al = len;
	int bl = conj_bitstr.len;
	char* temp = new char[l + 1];

	for (int i = 0; i < l; i++) {
		
		if ((bs[al - 1 - i] == '1') && (conj_bitstr.bs[bl - 1 - i] == '1'))temp[l - 1 - i] = '1';
		else temp[l - 1 - i] = '0';
		
	}
	
	temp[l] = '\0';
	std::string str = std::string(temp);
	delete[] temp;
	int found = str.find("1");
	
	if (found != std::string::npos) str = str.substr(found);
	else str = "0";
	
	BitString* str_res = new BitString(str);
	return *str_res;
}

BitString& BitString::conjaction(const BitString& conj_bitstr) const {

	if (len > conj_bitstr.len) return conjaction_repeat(conj_bitstr, conj_bitstr.len);
	else return conjaction_repeat(conj_bitstr, len);

}

void BitString::FileInput(std::string filename) {

	std::ifstream file(filename);

	if (!file.is_open()) {

		std::cout << "\n" << "Can't open file: " << filename << std::endl;
		exit(0);
	
	}

	std::string str;
	getline(file, str);

	if (bs) delete[] bs;

	mas_from_string(str);
	file.close();
	std::cout << "The string was obtained from a file(";

	for (int i = 0; i < len; i++) std::cout << bs[i];

	std::cout << ")" << std::endl;

}

void BitString::FileOutput() {

	std::ofstream write("output_file.txt");
	write << "Result of conjunction: ";

	for (int i = 0; i < len; i++) write << bs[i];

	write.close();
	std::cout << "\nResult was written to a file: output_file.txt" << std::endl;

}

void BitString::mas_from_string(std::string str) {

	char temp;
	len = str.length();
	bs = new unsigned char[len + 1];

	for (int i = 0; i < len; i++) bs[i] = '0';

	int i = 0;
	temp = str[i];

	while (temp != '\0') {

		if ((temp != '0') && (temp != '1')) {

			std::cout << "Incorrect input" << std::endl;
			exit(0);
		
		}

		bs[i] = (unsigned char)temp;
		temp = str[++i];

	}

	bs[len] = '\0';

}

BitString::~BitString() {

	delete[] bs;
	len = 0;

}

BitString& BitString::operator=(const BitString& str) {

	if (&str == this) return *this;

	if (bs) delete[] bs;

	len = str.len;
	bs = new unsigned char[len];

	for (int i = 0; i < len; i++) bs[i] = str.bs[i];

	return *this;

}

unsigned char& BitString::operator[](int i) {

	unsigned char error = -1;

	if ((i < 0) || (i > len)) return error;

	return bs[i];

}

BitString& operator&(const BitString& str1, const BitString& str2) {
	
	return str1.conjaction(str2);

}

std::ostream& operator<<(std::ostream& c_out, const BitString& i_str) {
	
	for (int i = 0; i < i_str.len; i++) c_out << i_str.bs[i];

	return c_out;

}

std::istream& operator>>(std::istream& c_in, BitString& o_str) {
	std::string str;
	getline(c_in, str);
	
	if (o_str.bs) delete[] o_str.bs;
	
	o_str.mas_from_string(str);
	return c_in;
}