#include "Person.h"

Person::Person() {
	name = "";
	surname = "";
	age = 0;
}

Person::Person(string name, string surname, unsigned short age) : name(name), surname(surname), age(age) {}