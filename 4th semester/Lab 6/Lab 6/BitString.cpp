#include "BitString.h"

#include <iostream>
#include <fstream>

using namespace std;

BitString::BitString() {

	mas = 0;
	len = 0;

}

BitString::BitString(string str) {

	mas_from_string(str);

}

BitString::BitString(const BitString& b) {

	len = b.len;
	mas = new unsigned char[len];

	for (int i = 0; i <= len; i++) mas[i] = b.mas[i];

}

void BitString::InputFunc() {
	string str;
	getline(cin, str);

	if (mas) delete[] mas;

	mas_from_string(str);
}

void BitString::ShowResult() {

	for (int i = 0; i < len; i++) cout << mas[i];

	cout << endl;

}

BitString& BitString::conjaction_repeat(const BitString& conj_bitstr, int len){

	int al = this -> len - 1;
	int bl = conj_bitstr.len - 1;
	char* temp = new char[len + 1];

	for (int i = 0; i < len; i++) {
		if ((al - i >= 0) && (bl - i >= 0)) {
			if ((mas[al - i] == '1') && (conj_bitstr.mas[bl - i] == '1'))temp[len - 1 - i] = '1';
			else temp[len - 1 - i] = '0';
		}
	}

	temp[len] = '\0';
	string str = string(temp);
	delete[] temp;
	int found = str.find("1");

	if (found != string::npos) str = str.substr(found);
	else str = "0";

	BitString* str_res = new BitString(str);
	return *str_res;
}

BitString& BitString::conjaction(const BitString& conj_bitstr) {

	if (len > conj_bitstr.len) return conjaction_repeat(conj_bitstr, conj_bitstr.len);
	else return conjaction_repeat(conj_bitstr, len);

}

void BitString::FileInput(string filename) {

	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("Can't open file");

	string str;
	getline(file, str);
	
	if (mas) delete[] mas;

	mas_from_string(str);
	file.close();

}

void BitString::FileOutput(string filename) {
	ofstream file(filename);

	if (!file.is_open())throw runtime_error("Can't open file");

	for (int i = 0; i < len; i++) file << mas[i];

	file.close();
}

void BitString::mas_from_string(string str) {

	char temp;
	len = str.length();
	mas = new unsigned char[len];

	for (int i = 0; i < len; i++) mas[i] = '0';

	int i = 0;
	temp = str[i];

	while (temp != '\0') {

		if ((temp != '0') && (temp != '1')) throw runtime_error("Incorrect string");

		mas[i] = (unsigned char)temp;
		temp = str[++i];

	}

}

BitString::~BitString() { delete[] mas; }

BitString& BitString::operator=(const BitString& str) {

	if (mas) delete[] mas;
	len = str.len;
	mas = new unsigned char[len];
	for (int i = 0; i < len; i++) mas[i] = str.mas[i];
	return *this;

}

unsigned char& BitString::operator[](int i) {

	if ((i >= 0) && (i < len)) return mas[len-i-1];
	else throw runtime_error("Index out of range");


}

BitString& operator&(BitString& str1, BitString& str2) {return str1.conjaction(str2);}

ostream& operator<<(ostream& out, BitString& a) {
	for (int j = 0; j < a.len; j++)
		out << a.mas[j];
	return out;
}

istream& operator>>(istream& c_in, BitString& o_str) {
	std::string str;
	getline(c_in, str);

	if (o_str.mas) delete[] o_str.mas;

	o_str.mas_from_string(str);
	return c_in;
}