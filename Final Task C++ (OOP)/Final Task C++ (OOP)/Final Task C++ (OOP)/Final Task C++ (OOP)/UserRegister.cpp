#include "UserRgister.h"
#include <string>


namespace UserRegister {

	void Register(vector<UserAccaunt>& useraccaunts) {

		system("cls");

		string name, surname, login, password, age_str;

		short age;

		unsigned short kod;

		system("cls");

		cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

		kod = _getch();

		if (kod == ESC)
			UserLoginMenyu::All();

		system("cls");

		cout << "\t\t\t\t\t\t\tRegister User:" << endl;

		cout << "Ad Daxil Edin: ";

		cin >> name;

		cout << "Soyad Daxil Edin: ";

		cin >> surname;

		cout << "Yas Daxil Edin: ";

		cin >> age_str;

		age = stoi(age_str);

		cout << "Login Daxil Edin: ";

		cin >> login;

		cout << "Password Daxil Edin: ";

		cin >> password;

		useraccaunts.push_back(UserAccaunt(name, surname, age, login, password));

		cout << "Registrasiya olundu:";

		Sleep(1200);

		UserLoginMenyu::All();

	}

}