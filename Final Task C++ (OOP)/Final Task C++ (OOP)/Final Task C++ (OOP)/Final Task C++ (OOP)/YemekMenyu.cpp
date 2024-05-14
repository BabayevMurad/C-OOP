#include "YemekMenyu.h"
#include "AdminMenyu.h"
#include "YemeklerAmbar.h"
#include "YemekAdd.h"
#include "Exceptions.h"

namespace YemekMenyu {

	void Menyu() {

		system("cls");

		vector<string> menyu_choice;
		short color_choice = 0;

		menyu_choice.push_back("1.Exit");
		menyu_choice.push_back("2.Yemekler");
		menyu_choice.push_back("3.YemeklerAdd");
		short size = menyu_choice.size() - 1;

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\tYemekMenyu" << endl;

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
				Control(color_choice);

		};

	}

	void Control(short choice) {
		switch (choice + 1) {

		case 1:
			AdminMenyu::menyu();
			break;

		case 2:
			Evvel:
			try {
				YemeklerAmbar::Consol();
			}
			catch (equal_name eyni) {
				system("cls");
				cout << eyni.what();
				Sleep(1500);
				goto Evvel;
			}
			catch (int_input_str sehf) {
				system("cls");
				cout << sehf.what();
				Sleep(1500);
				goto Evvel;
			}
			catch (Error& error) {
				system("cls");
				cout << "Yemek Yoxdu:";
				Sleep(1500);
				Menyu();
			}
			break;

		case 3:
			Evvel1:
			try {
				YemekAdd::Menyu();
			}
			catch (equal_name eyni) {
				system("cls");
				cout << eyni.what();
				Sleep(1500);
				goto Evvel1;
			}
			catch (int_input_str sehf) {
				system("cls");
				cout << sehf.what();
				Sleep(1500);
				goto Evvel1;
			}
			catch (Error& error) {
				system("cls");
				cout << "Ingredient Yoxdu:";
				Sleep(1500);
				Menyu();
			}
			catch (...) {
				system("cls");
				cout << "Xais Olunur Reqem Daxil Edin:";
				Sleep(1500);
				goto Evvel1;
			}
			break;

		default:
			break;
		}
	}

}