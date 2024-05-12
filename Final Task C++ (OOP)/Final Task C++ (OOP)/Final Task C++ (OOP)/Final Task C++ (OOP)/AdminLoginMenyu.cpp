#include "AdminLoginMenyu.h"
#include "VectorAdminAccaunt.h"

namespace AdminLoginMenyu {

	int Console() {

		system("cls");

		vector<string> menyu;

		short color_chocie = 0;

		menyu.push_back("1.Exit");
		menyu.push_back("2.Login");
		menyu.push_back("3.Register");

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\tLogin Menyu" << endl;

			for (size_t i = 0; i < menyu.size(); i++) {
				if (i == color_chocie) {
					change_color(GREEN);
					cout << menyu[i]<<endl;
					change_color(WHITE);
				}
				else
					cout << menyu[i]<<endl;
			}

			short kod = _getch();

			if (kod == DOWN) {
				if (color_chocie != 2)
					color_chocie++;
				else if (color_chocie == 2)
					color_chocie = 0;
			}

			else if (kod == UP) {
				if (color_chocie != 0)
					color_chocie--;
				else if (color_chocie == 0)
					color_chocie = 2;
			}

			else if (kod == ENTER) {
				return color_chocie;
			}
		}
	}

	void Control(short choice) {
		if (choice == 0)
			MainMenyu::Menyu();
		else if (choice == 1) {
			AccauntCheckAdmin::Check(AdminAccauntVector::accaunts);
		}
		else if (choice == 2) {
			Evvel:
			try {
				AdminRegister::Register(AdminAccauntVector::accaunts);
			}
			catch (...) {
				system("cls");

				cout << "Xais Olunur Reqem Daxil Edin.";

				Sleep(1500);

				goto Evvel;
			}
		}
	}

	void All() {
		Control(Console());
	}
}
