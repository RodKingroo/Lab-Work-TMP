#include "Buy.h"

Buy::Buy(): sum(0), sum_price(0.0), sum_weight(0.0){

}

void Buy::setSum(const int& value) {
	sum = (value >= 0 ? value : 0);
	sum_price = sum * getPrice();
	sum_weight = sum * getWeight();
}

int Buy::getSum() const { 
	return sum; 
}
double Buy::getSumPrice() const {
	return sum_price;
}

double Buy::getSumWeight() const {
	return sum_weight;
}