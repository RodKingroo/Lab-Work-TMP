#include "BitString.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void BitString::input() {

    string str;
    getline(cin, str);
    if (bs) delete[] bs;

    mas_from_string(str);

}

void BitString::FileInput(string filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Crash File" << endl;
        exit(0);
    }

    string str;
    getline(file, str);
    if (bs) delete[] bs;
    mas_from_string(str);

    file.close();
}

void BitString::output() {

    for (int j = 0; j < len; j++) {

        cout << bs[j];

    }

    cout << endl;

}

void BitString::FileOutput(string filename) {

    ofstream file(filename);
    file << "Result: ";

    for (int j = 0; j < len; j++) file << bs[j];

    file.close();

}

BitString BitString::conjaction(BitString b) {

    if (len > b.len) return conjaction_r(b,b.len);
    else return conjaction_r(b, len);

}

void BitString::mas_from_string(string str) {

    char tmp;
    len = str.length();
    bs = new unsigned char[len+1];
    for (int j = 0; j < len; j++) {

        bs[j] = '0';

    }

    int i = 0;
    tmp = str[i];

    while (tmp != '\0') {

        if ((tmp != '0') && (tmp != '1')) {

            cout << "Incorrect" << endl;
            exit(0);

        }

        bs[i] = (unsigned char) tmp;
        tmp = str[++i];
        //        cin.get(tmp);
    }
    bs[len] = '\0';
    i--;

}

BitString::BitString() {

    bs = 0;
    len = 0;

}

BitString::BitString(string inp_string) {

    mas_from_string(inp_string);

}

BitString::~BitString() {
    
    delete[] bs;
    len = 0;

}

BitString::BitString(const BitString& b) {
    len = b.len;
    bs = new unsigned char[len+1];

    for (int i = 0; i <= len; i++) {

        bs[i] = b.bs[i];

    }
}

BitString BitString::conjaction_r(BitString b, int l) {
    char* tmps = new char[l + 1];
    int al = len;
    int bl = b.len;

    for (int j = 0; j < 8; j++) {

        if ((bs[al - j - 1] == '1') && (b.bs[bl - j - 1] == '1')) {

            tmps[l - j - 1] = '1';

        }

        else {

            tmps[j] = '0';

        }

        tmps[l] = '\0';
        string str = string(tmps);
        delete[] tmps;
        int found = str.find('1');
        if (found != std::string::npos) {
            //int st = str.find('1');
            str = str.substr(found);
            break;
        }
        else str = "0";


        return BitString(str);
    }
}