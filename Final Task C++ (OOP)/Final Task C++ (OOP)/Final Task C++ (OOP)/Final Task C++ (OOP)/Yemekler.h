#pragma once

#include <iostream>
#include <vector>
#include "IngedientForArry.h"

using namespace std;

class Yemekler {

public:

	string name;

	string description;

	vector<IngedientForArry> ingredientleri;

	unsigned short price;


	Yemekler();

	Yemekler(string name, string description, vector<IngedientForArry> ingredientleri, unsigned short price);

	void showinfo();

	void showinfo_full();
};

