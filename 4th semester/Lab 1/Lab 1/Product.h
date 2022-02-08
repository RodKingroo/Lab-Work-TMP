#pragma once
class Product {
private:
	char name[50];
	double price;
	double weight;

public:
	Product();
	void setName(const char*);
	const char* getName() const;
	void setPrice(const double&);
	double getPrice() const;
	void setWeight(const double&);
	double getWeight() const;

};

