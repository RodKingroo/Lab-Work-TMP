#include <iostream>
#include "BitString.h"

using namespace std;

int main() {
	try {
		string choose_user;
		cout << "What input method do you want to use ? [console / file]: ";
		getline(cin, choose_user);
		if (choose_user == "console") {

			BitString b_str1;
			cout << "Write bit string 1: ";
			cin >> b_str1;
			cout << "Write bit string 2: ";
			string temp;
			getline(cin, temp);
			BitString b_str2(temp);
			BitString b_str_res = b_str1 & b_str2;
			b_str_res.show_result();
		
		} else if (choose_user == "file") {

			BitString b_file1, b_file2;
			b_file1.FileInput("a.txt");
			b_file2.FileInput("b.txt");
			BitString b_file3 = b_file1 & b_file2;
			b_file3.FileOutput();

		}
	}
	catch (runtime_error &error) {
		cout << "Exception: " << error.what() << endl;
	}
	return 0;
}