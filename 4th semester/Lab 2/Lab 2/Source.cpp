#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Rabbit.h"

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Какое животное вы хотите?" << endl << "1. Кошка"
		<< endl << "2. Собака"
		<< endl << "3. Кролик"
		<< endl << "(Выберете 1-3): ";

	int choise;
	cin >> choise;

	Pet* p;
	switch (choise) {
	case 1: p = new Cat(); break;
	case 2: p = new Dog(); break;
	case 3:	p = new Rabbit(); break;
	default: cout << "Ещё не завезли"; return 0;
	}
	cout << "Придумайте имя своему питомцу: ";
	char n[100];
	cin.ignore();
	cin.getline(n, 100);

	p->setName(n);
	p->play();
	delete p;
	
}