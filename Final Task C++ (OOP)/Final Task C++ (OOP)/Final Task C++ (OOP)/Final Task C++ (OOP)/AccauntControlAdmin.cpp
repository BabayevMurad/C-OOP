#include "AccauntControlAdmin.h"


namespace AccauntCheckAdmin {

	int Check(vector<AdminAccaunt>& adminaccaunts) {

		system("cls");

		string login, password;
		
		unsigned short kod;

		while (true) {

			system("cls");

			cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

			kod = _getch();

			if (kod == ESC)
				AdminLoginMenyu::All();
			
			system("cls");

			cout << "\t\t\t\t\t\t\tLogin:" << endl;

			cout << "Login Daxil Edin: ";

			cin >> login;

			cout << "Password Daxil Edin: ";

			cin >> password;

			for (short i = 0; i < adminaccaunts.size(); i++) {
				if (adminaccaunts[i].getLogin() == login && adminaccaunts[i].getPassword() == password) {
					AdminMenyu::menyu();
				}
			}

			cout << "Xaish olunur duzgun daxil edin." << endl;

			Sleep(2000);

		}
	}

}

