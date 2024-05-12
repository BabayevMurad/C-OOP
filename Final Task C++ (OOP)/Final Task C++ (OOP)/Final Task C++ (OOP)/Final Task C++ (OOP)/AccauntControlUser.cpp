#include "AccauntControlUser.h"


namespace AccauntCheckUser {

	int Check(vector<UserAccaunt>& useraccaunts) {

		system("cls");

		string login, password;

		unsigned short kod;

		while (true) {

			system("cls");

			cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

			kod = _getch();

			if (kod == ESC)
				UserLoginMenyu::All();

			system("cls");

			cout << "\t\t\t\t\t\t\tLogin User:" << endl;

			cout << "Login Daxil Edin: ";

			cin >> login;

			cout << "Password Daxil Edin: ";

			cin >> password;

			for (short i = 0; i < useraccaunts.size(); i++) {
				if (useraccaunts[i].getLogin() == login && useraccaunts[i].getPassword() == password) {
					UserMenyu::menyu(i);
				}
			}

			cout << "Xaish olunur duzgun daxil edin." << endl;

			Sleep(2000);

		}
	}

}

