#include "Yemekler.h"

Yemekler::Yemekler() {
	name = "";
	description = "";
	price = 0;
}

Yemekler::Yemekler(string name, string description,vector<IngedientForArry> ingredientleri, unsigned short price) : name(name), ingredientleri(ingredientleri), price(price) {}

void Yemekler::showinfo() {
	cout << "Name: " << name << " Price: " << price << endl;
}

void Yemekler::showinfo_full() {
	cout << "Name: " << name << " Description: " << description << " Price: " << price << endl;
}