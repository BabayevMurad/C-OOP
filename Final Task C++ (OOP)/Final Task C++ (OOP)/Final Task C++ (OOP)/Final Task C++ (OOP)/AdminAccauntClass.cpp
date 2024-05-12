#include "AdminAccauntClass.h"

AdminAccaunt::AdminAccaunt() : Admin() {
	login = "";
	password = "";
}

AdminAccaunt::AdminAccaunt(string name, string surname, unsigned short age, string login, string password) : Admin(name, surname, age) {
	this->login = login;
	this->password = password;
}

string AdminAccaunt::getLogin() {
	return login;
}

string AdminAccaunt::getPassword()
{
	return password;
}


