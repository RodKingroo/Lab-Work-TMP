#include "BitString.h"

#include <iostream>
#include <fstream>

using namespace std;

BitString::BitString() {

	bs = 0;
	len = 0;

}

BitString::BitString(string str) {

	mas_from_string(str);

}

BitString::BitString(const BitString& b) {

	len = b.len;
	bs = new unsigned char[len + 1];

	for (int i = 0; i <= len; i++) bs[i] = b.bs[i];


}

void BitString::InputFunc() {
	std::string str;
	getline(std::cin, str);

	if (bs) delete[] bs;

	mas_from_string(str);
}

void BitString::ShowResult() {

	for (int i = 0; i < len; i++) cout << bs[i];

	cout << endl;

}

BitString& BitString::conjaction_repeat(const BitString& conj_bitstr, int l) const{

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

void BitString::FileInput(string filename) {

	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("Can't open file: " + filename);

	string str;
	getline(file, str);
	
	if (bs) delete[] bs;

	mas_from_string(str);
	file.close();

}

void BitString::FileOutput(string filename) {
	ofstream file(filename);

	if (!file.is_open())throw runtime_error("Can't open file");

	for (int i = 0; i < len; i++) file << bs[i];

	file.close();
}

void BitString::mas_from_string(std::string str) {

	char temp;
	len = str.length();
	bs = new unsigned char[len + 1];

	for (int i = 0; i < len; i++) bs[i] = '0';

	int i = 0;
	temp = str[i];

	while (temp != '\0') {

		if ((temp != '0') && (temp != '1')) throw std::runtime_error("Incorrect string");

		bs[i] = (unsigned char)temp;
		temp = str[++i];

	}

	bs[len] = '\0';

}

BitString::~BitString() {

	delete[] bs;

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

	if ((i < 0) || (i > len)) throw std::runtime_error("Index out of range");

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