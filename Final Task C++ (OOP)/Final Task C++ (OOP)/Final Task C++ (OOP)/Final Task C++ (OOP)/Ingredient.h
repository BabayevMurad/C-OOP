#pragma once

#include <iostream>

using namespace std;

class Ingredient {

protected:
	
	string name;
	unsigned short price;

public:

	Ingredient();

	Ingredient(string name, unsigned short price);

};

