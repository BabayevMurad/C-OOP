#include "Ingredient.h"

Ingredient::Ingredient() {
	name = "";
	price = 0;
}

Ingredient::Ingredient(string name, unsigned short price) : name(name), price(price) {}