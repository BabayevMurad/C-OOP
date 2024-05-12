#pragma once

#include "Ingredient.h"


class IngedientForArry : public Ingredient {


	short count;

public:

	IngedientForArry();

	IngedientForArry(string name, unsigned short price, short count);

	short getCount();

	short getPrice();

	string getName();

	void setCount(unsigned short count);

	void setPrice(unsigned short count);

	void showinfomenyu();

	void showinfomeals();
};
