#include "AdminRegister.h"
#include <string>


namespace AdminRegister {

	void Register(vector<AdminAccaunt>& adminaccaunts) {

		system("cls");

		string name, surname,login, password, age_string;
		short age;

		unsigned short kod;

		system("cls");

		cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

		kod = _getch();

		if (kod == ESC)
			AdminLoginMenyu::All();

		system("cls");

		cout << "\t\t\t\t\t\t\tRegister:" << endl;

		cout << "Ad Daxil Edin: ";

		cin >> name;

		cout << "Soyad Daxil Edin: ";

		cin >> surname;

		cout << "Yas Daxil Edin: ";

		cin >> age_string;

		age = stoi(age_string);

		cout << "Login Daxil Edin: ";

		cin >> login;

		cout << "Password Daxil Edin: ";

		cin >> password;

		AdminAccaunt addAdmin(name, surname, age, login, password);

		adminaccaunts.push_back(addAdmin);

		cout << "Registrasiya olundu:";

		Sleep(1200);

		AdminLoginMenyu::All();

	}

}