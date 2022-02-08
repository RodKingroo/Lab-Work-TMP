#define _CRT_SECURE_NO_WARNINGS 1
#include "Product.h"
#include <cstring>

Product::Product() : price(0.0), weight(0.0) {

	for (int i = 0; i < 50; i++) {
		name[i] = '\0';
	}
}

void Product::setName(const char* name) {
	strcpy(this->name, name);
}

const char* Product::getName()const {
	return this->name;
}

void Product::setPrice(const double& price) {
	this->price = price;
}

double Product::getPrice() const { 
	return this->price; 
}

void Product::setWeight(const double& weight) {
	this->weight = weight;
}

double Product::getWeight() const {
	return this->weight;
}