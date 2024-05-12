#pragma once

#include "UserClass.h"
#include "Yemekler.h"
#include <vector>

class UserAccaunt : public User {

protected:

	string login;
	string password;


public:
	vector<Yemekler> history;
	vector<Yemekler> Sebet;

	UserAccaunt();

	UserAccaunt(string name, string surname, unsigned short age, string login, string password);

	string getLogin();

	string getName();

	string getSurname();

	int getAge();

	string getPassword();

};