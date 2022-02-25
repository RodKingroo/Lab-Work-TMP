#include <iostream>
#include <locale.h>
#include <map>

#include "BitString.h"

int main() {
	setlocale(LC_ALL, "rus");
	try {
		string choose_user;
		cout << "Какой вариант ввода вам нужен? [console / file]: ";
		getline(cin, choose_user);

		if (choose_user == "console") {

			BitString b_str1;
			cout << "Введите первую строку: ";
			cin >> b_str1;
			cout << "Введите вторую строку: ";
			string temp;
			getline(cin, temp);
			BitString b_str2(temp);
			BitString b_str_res = b_str1 & b_str2;
			b_str_res.show_result();

		}
		else if (choose_user == "file") {

			BitString b_file1, b_file2;
			b_file1.FileInput("a.txt");
			b_file2.FileInput("b.txt");
			BitString b_file3 = b_file1 & b_file2;
			b_file3.FileOutput();

		}
	}
	catch (runtime_error& error) {
		cout << "Exception: " << error.what() << endl;
	}
	return 0;
}