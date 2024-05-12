#include "Deyisenler.h"
#include "IngredientAddAmbarGekirXerc.h"
#include "VectorIngredient.h"

using namespace std;

namespace IngredientAdd {

	void elave() {

		system("cls");

		string name;

		short price, count;

		cout << "Cixmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		system("cls");

		if (kod_cixmaq == ESC)
			IngredientsMenyu::Menyu();

		cout << "\t\t\t\t\t\tIngredientAdd" << endl;

		cout << "Adi daxil edin:";

		cin >> name;

		cout << "Qiymeti daxil edin:";

		cin >> price;

		cout << "Count daxil edin:";

		cin >> count;

		for (size_t i = 0; i < IngredientVector::ingredients.size(); i++) {
			if (name == IngredientVector::ingredients[i].getName()) {
				cout << "Bele ingredient Var ";
				IngredientsMenyu::Menyu();
			}
		}

		if (Bucce < price * count) {

			cout << "Pul catmir:";

			Sleep(1500);

			IngredientsMenyu::Menyu();

		}
		else {

			Bucce -= price * count;

			IngredientVector::ingredients.push_back(IngedientForArry(name, price, count));


			Xerc_gunluk += count * price;
			Xerc_ayliq += count * price;

			cout << "Elave olundu:";

			Sleep(1500);

			IngredientsMenyu::Menyu();
		}


	}

}

namespace IngredientlerAmbar {

	IngedientForArry* change;
		
	void Consol() {

		system("cls");

		unsigned short color_choice = 0;

		short size_vector = IngredientVector::ingredients.size();

		if (size_vector == 0) {
			cout << "Ingredient Yoxdur: ";

			Sleep(1500);

			IngredientsMenyu::Menyu();
		}
		

		cout << "Evvele Qayitmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		if (kod_cixmaq == ESC)
			IngredientsMenyu::Menyu();

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\t\tAmbardaIngredient" << endl;

			cout << "Evvele Qayitmaq Ucun ESC Basin!!!:" << endl << endl;

			for (size_t i = 0; i < size_vector; i++) {
				if (i == color_choice) {
					change_color(GREEN);
					IngredientVector::ingredients[i].showinfomenyu();
					change_color(WHITE);
				}
				else
					IngredientVector::ingredients[i].showinfomenyu();
			}


			short kod = _getch();

			if (kod == DOWN) {
				if (color_choice != size_vector - 1)
					color_choice++;
				else if (color_choice == size_vector - 1)
					color_choice = 0;
			}

			else if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = size_vector - 1;
			}

			else if (kod == ENTER) {
				change = &IngredientVector::ingredients[color_choice];
				menyu_change();
			}

			else if (kod == ESC) {
				IngredientsMenyu::Menyu();
				change = nullptr;
			}
		}

	}

	void menyu_change() {

		system("cls");

		string menyu_arry[3] = {"Exit:", "Price:", "ConutAdd:"};

		short color_choice = 0;

		bool davam = true;

		while (davam) {

			system("cls");

			cout << "\t\t\t\t\t\t\tIngredientChange" << endl;

			for (size_t i = 0; i < 3; i++) {
				if (i == color_choice) {
					change_color(GREEN);
					cout << menyu_arry[i] << endl;
					change_color(WHITE);
				}
				else
					cout << menyu_arry[i] << endl;
			}

			short kod = _getch();

			if (kod == DOWN) {
				if (color_choice != 2)
					color_choice++;
				else if (color_choice == 2)
					color_choice = 0;
			}

			else if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = 2;
			}

			else if (kod == ENTER)
				control(color_choice, davam);
		}

	}

	void control(short choice, bool& davam) {
		switch (choice) {

		case 0:
			davam = false;
			break;
		case 1:
			priceChange();
			break;
		case 2:
			countChange();
			break;
		default:
			break;
		}
	}

	void priceChange() {
		system("cls");

		short price;

		cout << "Evvele Qayitmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		if (kod_cixmaq == ESC)
			return;

		system("cls");

		cout << "\t\t\t\t\t\t\tPriceChange" << endl;

		cout << "Qiymenti daxil edin: ";

		cin >> price;

		change->setPrice(price);

		cout << "Uqurla Deyisildi:";

		Sleep(1500);
	}

	void countChange() {
		system("cls");

		short conut;

		cout << "Evvele Qayitmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		if (kod_cixmaq == ESC)
			return;

		system("cls");

		cout << "\t\t\t\t\t\t\tCountChange" << endl;

		cout << "Sayini daxil edin: ";

		cin >> conut;

		conut += change->getCount();

		Bucce -= conut * change->getPrice();

		Xerc_ayliq += conut * change->getPrice();
		Xerc_gunluk += conut * change->getPrice();

		change->setCount(conut);

		cout << "Uqurla Deyisildi:";

		Sleep(1500);
	}

}

namespace GelirXerc {

	void Gelir() {
		system("cls");

		cout << "\t\t\t\t\t\t\tGelir:" << endl;

		cout << "Gunluk: " << Gelir_gunluk << endl;
		cout << "Ayliq: " << Gelir_ayliq << endl;

		cout << "Evvele Qayitmaq Ucun ESC:" << endl;

		int kod = _getch();

		if (kod == ESC)
			AdminMenyu::menyu();
	}

	void Xerc() {
		system("cls");

		cout << "\t\t\t\t\t\tXerc:" << endl;

		cout << "Gunluk: " << Xerc_gunluk << endl;
		cout << "Ayliq: " << Xerc_ayliq << endl;

		cout << "Evvele Qayitmaq Ucun ESC:" << endl;

		int kod = _getch();

		if (kod == ESC)
			AdminMenyu::menyu();
	}

}

#include "YemekAdd.h"

#include "VectorIngredient.h"

#include "YemekMenyu.h"

#include "YemeklerVector.h"

namespace YemekAdd {

	vector<IngedientForArry> ingformeals;


	void Menyu() {

		system("cls");

		string name, description;

		unsigned short price = 0;

		unsigned short price_daxil;

		if (IngredientVector::ingredients.size() == 0) {
			cout << "Ingredient Yoxdur: ";

			Sleep(1500);

			YemekMenyu::Menyu();
		}

		cout << "Cixmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		system("cls");

		if (kod_cixmaq == ESC)
			YemekMenyu::Menyu();

		cout << "\t\t\t\t\tYemekAdd" << endl;

		cout << "Adi daxil edin: ";

		cin >> name;

		cout << "Informasiya daxil edin: ";

		cin >> description;

		IngredientElave(price);

		cout << "Qiymeti Daxil Edin (Bu qiymetde ingredient xerci syayilib): ";

		cin >> price_daxil;

		price += price_daxil;

		cout << "Elave olundu: ";

		Sleep(1500);

		YemeklerVector::yemekler.push_back(Yemekler(name, description, ingformeals, price));

		YemekMenyu::Menyu();
	}

	void IngredientElave(unsigned short& price) {
		while (true) {

			system("cls");

			short color_choice = 0;

			cout << "\t\t\t\t\tYemekAdd:" << endl;


			for (size_t i = 0; i < IngredientVector::ingredients.size(); i++) {
				if (color_choice == i) {
					change_color(GREEN);
					IngredientVector::ingredients[i].showinfomeals();
					change_color(WHITE);
				}
			}

			cout << "Cixmaq Ucun ESC Basin; Secmek Ucun Enter; Davam Etmek Ucun D basin:";

			short kod = _getch();

			if (kod == ESC)
				YemekMenyu::Menyu();
			else if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = 0;
			}
			else if (kod == DOWN) {
				if (color_choice != IngredientVector::ingredients.size() - 1)
					color_choice++;
				else if (color_choice == IngredientVector::ingredients.size() - 1)
					color_choice = IngredientVector::ingredients.size() - 1;
			}

			else if (kod == ENTER) {
				system("cls");

				short count;

				cout << "Sayini daxil edin: ";

				cin >> count;

				price += IngredientVector::ingredients[color_choice].getPrice() * count;

				IngedientForArry ingredientyemekucun = IngredientVector::ingredients[color_choice];

				ingredientyemekucun.setCount(count);

				ingformeals.push_back(ingredientyemekucun);

				cout << "Ingredient Elave olundu";

				Sleep(1500);
			}

			else if (kod == RIGHT) {
				return;
			}

		}
	}

}

#include "YemeklerAmbar.h"

namespace YemeklerAmbar {

	void Consol() {

		system("cls");

		if (IngredientVector::ingredients.size() == 0) {
			cout << "Yemek Yoxdur: ";

			Sleep(1500);

			YemekMenyu::Menyu();
		}

		cout << "\t\t\t\t\t\t\tAmbardaIngredient" << endl;

		for (size_t i = 0; i < YemeklerVector::yemekler.size(); i++) {
			YemeklerVector::yemekler[i].showinfo();
		}

		cout << "Evvele Qayitmaq Ucun ESC Basin:";

		short kod = _getch();

		if (kod == ESC)
			YemekMenyu::Menyu();
	}

}