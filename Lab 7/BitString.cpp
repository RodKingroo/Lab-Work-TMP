#include "BitString.h"
#include <iostream>

using namespace std;

int main() {

	BitString a("11");
	BitString b("1110");
	cout << "a=";
	a.output();
	cout << "b=";
	b.output();

	BitString c = a.conjaction(b);
	cout << "a&b=";
	c.output();

}