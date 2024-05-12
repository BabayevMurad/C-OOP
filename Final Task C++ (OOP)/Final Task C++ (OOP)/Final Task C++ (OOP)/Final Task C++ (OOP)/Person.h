#pragma once

#include <iostream>

using namespace std;

class Person {

protected:

	string name;
	string surname;
	unsigned short age;

public:

	Person();

	Person(string name, string surname, unsigned short age);

};
