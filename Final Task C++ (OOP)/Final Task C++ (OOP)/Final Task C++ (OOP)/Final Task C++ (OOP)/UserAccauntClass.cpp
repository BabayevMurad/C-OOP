#include "UserAccauntClass.h"

UserAccaunt::UserAccaunt() : User() {
	login = "";
	password = "";
}

UserAccaunt::UserAccaunt(string name, string surname, unsigned short age, string login, string password) : User(name, surname, age) {
	this->login = login;
	this->password = password;
}

string UserAccaunt::getLogin() {
	return login;
}

string UserAccaunt::getName()
{
	return name;
}

string UserAccaunt::getSurname()
{
	return surname;
}

int UserAccaunt::getAge()
{
	return age;
}

string UserAccaunt::getPassword()
{
	return password;
}


