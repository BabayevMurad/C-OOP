#include "MainMenyu.h"

namespace MainMenyu {

	void Console_1() { // Esas Menyudur.

		system("cls");

		short color_choice = 1;

		vector<string> main_menyu_choice_1;
		main_menyu_choice_1.push_back("1.Exit:");
		main_menyu_choice_1.push_back("2.Admin:");
		main_menyu_choice_1.push_back("3.User:");

		while (true) {
			system("cls");
			cout << "\t\t\t\t\t\tWelcome To Restaurant" << endl;
			short iteration_for_menyu = 1;
			for (auto vector_element = main_menyu_choice_1.begin(); vector_element != main_menyu_choice_1.end(); vector_element++) {
				if (color_choice == iteration_for_menyu) {
					change_color(GREEN);
					cout << *vector_element << endl;
					change_color(WHITE);
				}

				else
					cout << *vector_element << endl;

				iteration_for_menyu++;
			}

			short choice = _getch();

			if (choice == UP) {
				if (color_choice != 1)
					color_choice--;
				else if (color_choice == 1)
					color_choice = 3;
			}

			if (choice == DOWN) {
				if (color_choice != 3)
					color_choice++;
				else if (color_choice == 3)
					color_choice = 1;
			}

			if (choice == ENTER) {
				Console_1_Control(color_choice);
			}

		}

	}

	void Console_1_Control(int choice) { //Secimi yoxlamaq ucun.

		if (choice == 1) {
			exit(1);
		}

		else if (choice == 2) {
			AdminLoginMenyu::All();
		}

		else if (choice == 3) {
			UserLoginMenyu::All();
		}

	}

	void Menyu() {
		Console_1();
	}
}