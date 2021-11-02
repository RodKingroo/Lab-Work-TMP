#include "BitString.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void BitString::input() {

    char tmp;
    unsigned char tmps[8];
    
    for (int j = 0; j < 8; j++) {

        tmps[j] = '0';

    }

    int i = 0;
    cin.get(tmp);
    
    while (tmp != '\n') {
    
        if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
    
            cout << "Incorrect" << endl;
            exit(0);
        
        }
        
        tmps[i] = (unsigned char)tmp;
        cin.get(tmp);
        i++;
    }

    i--;
    
    for (int j = 0; j <= i; j++) {

        bs[7 - i + j] = tmps[j];

    }
}

void BitString::FileInput(string filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Crash File" << endl;
        exit(0);
    }

    char tmp;
    unsigned char tmps[8];
    for (int j = 0; j < 8; j++) tmps[j] = '0';
    int i = 0;
    while (file.get(tmp)) {
        if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {
            cout << "Incorrect" << endl;
            exit(0);
        }
        tmps[i] = (unsigned char)tmp;
        i++;
    }

    i--;
    for (int j = 0; j <= i; j++) {
     
        bs[7 - i + j] = tmps[j];
    
    }

    file.close();
}

void BitString::output() {
	
    for (int j = 0; j < 8; j++) {

        cout << bs[j];
    
    }
        
    cout << endl;

}

void BitString::FileOutput(string filename) {

    ofstream file(filename);
    file << "Результат: ";

    for (int j = 0; j < 8; j++) file << bs[j];

    file.close();

}

BitString BitString::conjaction(BitString b) {
    char tmps[9];
    
    for (int j = 0; j < 8; j++) {
    
        tmps[j] = '0';
    
    }

    for (int j = 0; j < 8; j++) {

        if ((bs[j] == '1') && (b.bs[j] == '1')) {
         
           tmps[j] = '1';
        
       }

        else {
         
           tmps[j] = '0';
        
        }

        tmps[8] = '\0';


    }

    return BitString(std::string(tmps));

}

BitString::BitString() {
    
    for (int j = 0; j < 8; j++) {

        bs[j] = 0;

    }

}

BitString::BitString(string inp_string) {

    for (int j = 0; j < 8; j++) {

        bs[j] = 0;

    }


    char tmp;
    unsigned char tmps[8];

    for (int j = 0; j < 8; j++) {

        tmps[j] = '0';

    }

    int i = 0;
    tmp = inp_string[i];

    while (tmp != '\0') {

        if (((tmp != '0') && (tmp != '1')) || (i >= 8)) {

            cout << "Incorrect" << endl;
            exit(0);

        }

        tmps[i] = (unsigned char)tmp;
        tmp = inp_string[++i];
//        cin.get(tmp);
    }

    i--;

    for (int j = 0; j <= i; j++) {

        bs[7 - i + j] = tmps[j];

    }

}

