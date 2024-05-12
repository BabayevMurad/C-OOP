#pragma once

#include "AdminClass.h"

class AdminAccaunt : public Admin {

protected:

	string login;
	string password;

public:

	AdminAccaunt();

	AdminAccaunt(string name, string surname, unsigned short age, string login, string password);

	string getLogin();

	string getPassword();

};