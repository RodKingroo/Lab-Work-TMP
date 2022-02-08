#include "Check.h"
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	Check product;
	product.setName("\"Уральские\" пельмени");
	product.setPrice(12);
	product.setWeight(1);
	product.setSum(30);
	product.printProductInfo();
	product.printBuyInfo();
	system("pause");
	return 0;

}