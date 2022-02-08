#include "BitString.h"
#include <iostream>

using namespace std;

int main() {

	BitString a, b, c;
	//cout << "Enter 1 BitString: " << endl;
	//a.input();
	a.FileInput("a.txt");
	
	cout << "Enter 2 BitString: " << endl;
	b.input();

	c = a.conjaction(b);
	//c.output();
	c.FileOutput("c.txt");
	cout << "Result in c.txt" << endl;

}