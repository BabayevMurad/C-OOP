#include "UserMenyu.h"
#include "Zakaz.h"
#include "YemekSebet.h"
#include "UserHistory.h"
#include "Exceptions.h"

namespace UserMenyu {

	void menyu(short index) {

		system("cls");

		vector<string> menyu_choice;
		short color_choice = 0;

		menyu_choice.push_back("1.Exit");
		menyu_choice.push_back("2.Zakaz");
		menyu_choice.push_back("3.Sebet");
		menyu_choice.push_back("4.History");

		short size = menyu_choice.size() - 1;

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\t\tUserMenyu" << endl;

			for (size_t i = 0; i < menyu_choice.size(); i++) {

				if (i == color_choice) {

					change_color(GREEN);
					cout << menyu_choice[i] << endl;
					change_color(WHITE);

				}

				else
					cout << menyu_choice[i] << endl;

			}

			short kod = _getch();

			if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = size;
			}

			else if (kod == DOWN) {
				if (color_choice != size)
					color_choice++;
				else if (color_choice == size)
					color_choice = 0;
			}

			else if (kod == ENTER)
				control(color_choice, index);

		}

	}

	void control(short choice, short index_menyu) {
		switch (choice + 1) {

		case 1:
			UserLoginMenyu::All();
			break;
		case 2:
			Evvel1:
			try {
				YemekZakaz::menyu(index_menyu);
			}
			catch (equal_name eyni) {
				system("cls");
				eyni.what();
				Sleep(1500);
				goto Evvel1;
			}
			catch (int_input_str sehf) {
				system("cls");
				sehf.what();
				Sleep(1500);
				goto Evvel1;

			}
			catch (Error error) {
				system("cls");
				error.what();
				cout << "Menyu Bosdur";
				Sleep(1500);
				menyu(index_menyu);
			}
			break;
		case 3:
			Evvel2:
			try {
				YemekSebet::menyu(index_menyu);
			}
			catch (equal_name eyni) {
				system("cls");
				eyni.what();
				Sleep(1500);
				goto Evvel2;
			}
			catch (int_input_str sehf) {
				system("cls");
				sehf.what();
				Sleep(1500);
				goto Evvel2;

			}
			catch (Error error) {
				system("cls");
				cout << "Sebet Bosdur:";
				Sleep(1500);
				menyu(index_menyu);
			}
			break;
		case 4:
			Evvel3:
			try {
				History::history(index_menyu);
			}
			catch (equal_name eyni) {
				system("cls");
				eyni.what();
				Sleep(1500);
				goto Evvel3;
			}
			catch (int_input_str sehf) {
				system("cls");
				sehf.what();
				Sleep(1500);
				goto Evvel3;

			}
			catch (Error error) {
				system("cls");
				cout << "History Yoxdu";
				Sleep(1500);
			}
			break;
		default:
			break;
		}
	}

}