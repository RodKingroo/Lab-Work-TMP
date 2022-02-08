#pragma once
#include "Buy.h"
#include <iostream>

using namespace std;

class Check :public Buy{

public:
	void printProductInfo() {
		cout << "Товар: " << getName() << endl;
		cout << "Цена: " << getPrice() << " руб. \n";
		cout << "Вес: " << getWeight() << " кг. \n\n";
	}

	void printBuyInfo() {
		cout << "Товара куплено: " << getSum() << " шт. \n";
		cout << "На сумму: " << getSumPrice() << " руб. \n";
		cout << "Общий вес: " << getSumWeight() << " кг. \n\n";
	}
};

