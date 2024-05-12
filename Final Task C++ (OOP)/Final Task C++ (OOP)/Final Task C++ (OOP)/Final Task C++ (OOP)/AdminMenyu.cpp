#include "AdminMenyu.h"
#include "AdminLoginMenyu.h"
#include "IngredientsMenyu.h"
#include "YemekMenyu.h"

namespace AdminMenyu {

	void menyu() {

		system("cls");

		vector<string> menyu_choice;
		short color_choice = 0;

		menyu_choice.push_back("1.Exit");
		menyu_choice.push_back("2.Ingredient");
		menyu_choice.push_back("3.Meals");
		menyu_choice.push_back("4.Profit");
		menyu_choice.push_back("5.Expenses");

		short size = menyu_choice.size() - 1;

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\t\tAdminMenyu" << endl;

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
				control(color_choice);

		}
		
	}

	void control(short choice) {
		switch (choice+1) {

		case 1:
			AdminLoginMenyu::All();
			break;
		case 2:
			IngredientsMenyu::Menyu();
			break;
		case 3:
			YemekMenyu::Menyu();
			break;
		case 4:
			GelirXerc::Gelir();
			break;
		case 5:
			GelirXerc::Xerc();
			break;
		default:
			break;
		}
	}

}