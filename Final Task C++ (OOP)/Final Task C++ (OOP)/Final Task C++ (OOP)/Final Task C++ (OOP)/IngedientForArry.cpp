#include "IngedientForArry.h"

IngedientForArry::IngedientForArry() : Ingredient() {
	count = 0;
}

IngedientForArry::IngedientForArry(string name, unsigned short price, short count) : Ingredient(name, price) {
	this->count = count;
}

short IngedientForArry::getCount() {
	return count;
}

short IngedientForArry::getPrice() {
	return price;
}

string IngedientForArry::getName() {
	return name;
}

void IngedientForArry::setCount(unsigned short count) {
	this->count = count;
}

void IngedientForArry::setPrice(unsigned short price) {
	this->price = price;
}

void IngedientForArry::showinfomenyu() {
	cout << "Name: " << name << " Count: " << count << " Price:" << price << endl;
}

void IngedientForArry::showinfomeals() {
	if (count > 0)
		cout << "Name: " << name << endl;
}