#include "IngredientsMenyu.h"
#include "Vectoristifade.h"
#include "Exceptions.h"

namespace IngredientsMenyu {

	void Menyu() {

		system("cls");

		vector<string> menyu_choice;
		short color_choice = 0;

		menyu_choice.push_back("1.Exit");
		menyu_choice.push_back("2.Ingredients");
		menyu_choice.push_back("3.IngredientAdd");
		short size = menyu_choice.size() - 1;

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\tIngredientMenyu" << endl;

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
			IngredientlerAmbar::Consol();
			break;

		case 3:
			Evvel:
			try {
				IngredientAdd::elave();
			}
			catch (Error error) {
				system("cls");

				cout << error.what();

				Sleep(1500);

				goto Evvel;
			}
			break;

		default:
			break;
		}
	}

}