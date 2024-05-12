#include "Deyisenler.h"
#include "VectorIstifade.h"
#include "VectorIngredient.h"
#include "Exceptions.h"
#include <string>
#include "UserAccauntVector.h"

using namespace std;

namespace IngredientAdd {

	void elave() {

		system("cls");

		string name;

		short price, count;
		string price_str, count_str;

		cout << "Cixmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		system("cls");

		if (kod_cixmaq == ESC)
			IngredientsMenyu::Menyu();

		cout << "\t\t\t\t\t\tIngredientAdd" << endl;

		cout << "Adi daxil edin:";

		cin >> name;

		cout << "Qiymeti daxil edin:";

		cin >> price_str;

		cout << "Count daxil edin:";

		cin >> count_str;

		price = stoi(price_str);
		count = stoi(count_str);

		for (size_t i = 0; i < IngredientVector::ingredients.size(); i++) {
			if (name == IngredientVector::ingredients[i].getName()) {
				throw Error("Bele ingredient Var:");
			}
		}

		if (Bucce < price * count) {

			cout << "Pul catmir:";

			throw Error("Pul catmir:");

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

			cout << endl << "Deyismek Ucun Enter Basin:" << endl;

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

		string menyu_arry[3] = { "Exit:", "Price:", "ConutAdd:" };

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
			try {
				priceChange();
			}
			catch (...) {
				system("cls");

				cout << "Xais Olunur Reqem Daxil Edin:";

				Sleep(1200);

				Consol();
			}
			break;
		case 2:
			try {
				countChange();
			}
			catch (...) {
				system("cls");

				cout << "Xais Olunur Reqem Daxil Edin:";

				Sleep(1200);

				Consol();
			}
			break;
		default:
			break;
		}
	}

	void priceChange() {
		system("cls");

		string price_str;
		short price;

		cout << "Evvele Qayitmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		if (kod_cixmaq == ESC)
			return;

		system("cls");

		cout << "\t\t\t\t\t\t\tPriceChange" << endl;

		cout << "Qiymenti daxil edin: ";

		cin >> price_str;

		price = stoi(price_str);

		change->setPrice(price);

		cout << "Uqurla Deyisildi:";

		Sleep(1500);
	}

	void countChange() {
		system("cls");

		short conut;
		string conut_str;

		cout << "Evvele Qayitmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		if (kod_cixmaq == ESC)
			return;

		system("cls");

		cout << "\t\t\t\t\t\t\tCountChange" << endl;

		cout << "Sayini daxil edin: ";

		cin >> conut_str;

		conut = stoi(conut_str);

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

		cout << "Bucce: " << Bucce << endl;
		cout << "Gunluk: " << Gelir_gunluk << endl;
		cout << "Ayliq: " << Gelir_ayliq << endl;

		cout << "Evvele Qayitmaq Ucun ESC:" << endl;

		int kod = _getch();

		if (kod == ESC)
			AdminMenyu::menyu();
	}

	void Xerc() {
		system("cls");

		cout << "\t\t\t\t\t\t\Xerc:" << endl;

		cout << "Bucce: " << Bucce << endl;
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
		string price_daxil_srt;

		if (IngredientVector::ingredients.size() == 0) {
			throw Error("Ingredient Yoxdur");
		}

		cout << "Cixmaq Ucun ESC Basin Eks Halda Istenilen Knopkani Basin:" << endl;

		short kod_cixmaq = _getch();

		system("cls");

		if (kod_cixmaq == ESC)
			YemekMenyu::Menyu();

		cout << "\t\t\t\t\tYemekAdd" << endl;

		cout << "Adi daxil edin: ";

		cin >> name;

		for (size_t i = 0; i < YemeklerVector::yemekler.size(); i++) {
			if (YemeklerVector::yemekler[i].name == name) {
				throw equal_name();
			}
		}

		cout << "Informasiya daxil edin: ";

		cin >> description;

		IngredientElave(price);

		system("cls");

		cout << "Qiymeti Daxil Edin: ";

		cin >> price_daxil_srt;

		price_daxil = stoi(price_daxil_srt);

		price += price_daxil;

		cout << "Elave olundu: ";

		Sleep(1500);

		YemeklerVector::yemekler.push_back(Yemekler(name, description, ingformeals, price));

		YemekMenyu::Menyu();
	}

	void IngredientElave(unsigned short& price) {
		short color_choice = 0;
		while (true) {

			system("cls");


			cout << "\t\t\t\t\tYemekAdd:" << endl;


			for (size_t i = 0; i < IngredientVector::ingredients.size(); i++) {
				if (color_choice == i) {
					change_color(GREEN);
					IngredientVector::ingredients[i].showinfomeals();
					change_color(WHITE);
				}
				else {
					IngredientVector::ingredients[i].showinfomeals();
				}
			}

			cout << "Secmek Ucun Enter; Davam Etmek Ucun D basin:";

			short kod = _getch();

			if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = IngredientVector::ingredients.size() - 1;
			}
			else if (kod == DOWN) {
				if (color_choice != IngredientVector::ingredients.size() - 1)
					color_choice++;
				else if (color_choice == IngredientVector::ingredients.size() - 1)
					color_choice = 0;
			}

			else if (kod == ENTER) {
				system("cls");

				short count;
				string count_str;

				cout << "Sayini daxil edin: ";

				cin >> count_str;

				count = stoi(count_str);

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

		if (YemeklerVector::yemekler.size() == 0) {
			throw Error("Yemek Yoxdur:");
		}

		cout << "\t\t\t\t\t\t\tMenyudaYemek" << endl;

		for (size_t i = 0; i < YemeklerVector::yemekler.size(); i++) {
			YemeklerVector::yemekler[i].showinfo();
			cout << endl;
		}

		cout << "Evvele Qayitmaq Ucun ESC Basin:";

		short kod = _getch();

		if (kod == ESC)
			YemekMenyu::Menyu();
	}

}

#include "Zakaz.h"

#include "YemeklerVector.h"

namespace YemekZakaz {

	void menyu_yemek(Yemekler& yemek, short index_menyu);

	void Sebet_elave(Yemekler& yemek, short index_menyu);

	void Yoxlamaq(Yemekler& yemek, int color_choice, short index_menyu);

	void menyu(short index_menyu) {

		system("cls");

		if (YemeklerVector::yemekler.size() == 0) {
			throw Error("Menyu Bosdur:");
		}

		short say_yemek = 0;

		for (size_t i = 0; i < YemeklerVector::yemekler.size(); i++) {
			short say = 0;
			for (size_t j = 0; j < YemeklerVector::yemekler[i].ingredientleri.size(); j++) {
				for (size_t c = 0; c < IngredientVector::ingredients.size(); c++) {
					if (YemeklerVector::yemekler[i].ingredientleri[j].getName() == IngredientVector::ingredients[c].getName()) {
						if (YemeklerVector::yemekler[i].ingredientleri[j].getCount() <= IngredientVector::ingredients[c].getCount()) {
							say++;
						}
					}
				}
			}
			if (say == YemeklerVector::yemekler[i].ingredientleri.size()) {
				say_yemek++;
			}
		}

		if (say_yemek == 0) {
			cout << "Yemekler Out Of Stock:";

			Sleep(1500);

			AdminMenyu::menyu();
		}

		cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

		short kod_ilk = _getch();

		if (kod_ilk == ESC)
			AdminMenyu::menyu();

		short color_choice = 0;

		while (true) {
			system("cls");

			cout << "\t\t\t\t\tYemekZakaz:" << endl;

			cout << "Cixmaq ucun ESC Basin:" << endl;

			vector<Yemekler> duzgungelen;

			for (size_t i = 0; i < YemeklerVector::yemekler.size(); i++) {
				short say = 0;
				for (size_t j = 0; j < YemeklerVector::yemekler[i].ingredientleri.size(); j++) {
					for (size_t c = 0; c < IngredientVector::ingredients.size(); c++) {
						if (YemeklerVector::yemekler[i].ingredientleri[j].getName() == IngredientVector::ingredients[c].getName()) {
							if (YemeklerVector::yemekler[i].ingredientleri[j].getCount() <= IngredientVector::ingredients[c].getCount()) {
								say++;
							}
						}
					}
				}
				if (say == YemeklerVector::yemekler[i].ingredientleri.size()) {
					duzgungelen.push_back(YemeklerVector::yemekler[i]);
				}
			}

			for (size_t i = 0; i < duzgungelen.size(); i++) {
				if (i == color_choice) {
					change_color(GREEN);
					duzgungelen[i].showinfo();
					change_color(WHITE);
				}

				else {
					duzgungelen[i].showinfo();
				}
			}

			cout << "Secmek Ucun Enter: ";

			short kod = _getch();

			if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = duzgungelen.size() - 1;
				else {
					color_choice = color_choice;
				}
			}
			else if (kod == DOWN) {
				if (color_choice != duzgungelen.size() - 1)
					color_choice++;
				else if (color_choice == duzgungelen.size() - 1)
					color_choice = 0;
				else {
					color_choice = color_choice;
				}
			}

			else if (kod == ENTER) {
				menyu_yemek(duzgungelen[color_choice], index_menyu);
			}
			else if (kod == ESC) {
				UserMenyu::menyu(index_menyu);
			}
		}


	}

	void menyu_yemek(Yemekler& yemek, short index_menyu) {

		system("cls");

		string arry[3] = { "1.Exit:","2.SebeteElave:" };

		short color_choice = 0;

		bool davam = true;

		while (davam) {

			system("cls");

			cout << "\t\t\t\t\tYemekZakaz:" << endl;

			yemek.showinfo_full();

			cout << endl;

			for (size_t i = 0; i < 3; i++) {
				if (color_choice == i) {
					change_color(GREEN);
					cout << arry[i] << endl;
					change_color(WHITE);
				}
				else {
					cout << arry[i] << endl;
				}
			}

			cout << "Secmek Ucun Enter: ";

			short kod = _getch();



			if (kod == ESC)
				UserMenyu::menyu(index_menyu);
			else if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = 2;
			}
			else if (kod == DOWN) {
				if (color_choice != 1)
					color_choice++;
				else if (color_choice == 1)
					color_choice = 0;
			}

			else if (kod == ENTER) {
				Yoxlamaq(yemek, color_choice, index_menyu);
			}

		}
	}

	void Yoxlamaq(Yemekler& yemek, int color_choice, short index_menyu) {
		switch (color_choice) {

		case 0:
			menyu(index_menyu);
			break;

		case 1:
			Sebet_elave(yemek, index_menyu);
			break;

		default:
			break;
		}
	}

	void Sebet_elave(Yemekler& yemek, short index_menyu) {
		UserAccauntVector::accaunts[index_menyu].Sebet.push_back(yemek);

		cout << "Yemek Elave Olundu:" << endl;

		Sleep(1500);

		menyu(index_menyu);
	}



}

#include "YemekSebet.h"

namespace YemekSebet {

	void Sebet_yemek_menyu(Yemekler& yemek, short index_menyu);

	void Yoxlamaq(Yemekler& yemek, int color_choice, short index_menyu);

	void info(Yemekler& yemek, short index_menyu);

	void sebet_silme(Yemekler& yemek, short index, short index_menyu);

	void son_zakaz(Yemekler& yemek, short index, short index_menyu);

	void menyu(short index) {

		system("cls");

		if (UserAccauntVector::accaunts[index].Sebet.size() == 0) {
			throw Error("Sebet Bosdur:");
		}

		cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

		short kod_ilk = _getch();

		if (kod_ilk == ESC)
			UserMenyu::menyu(index);


		short color_choice = 0;

		while (true) {

			system("cls");

			cout << "\t\t\t\t\tYemekSebet:" << endl;

			cout << "Cixmaq ucun ESC Basin:" << endl;

			for (size_t i = 0; i < UserAccauntVector::accaunts[index].Sebet.size(); i++) {
				if (i == color_choice) {
					change_color(GREEN);
					UserAccauntVector::accaunts[index].Sebet[i].showinfo();
					change_color(WHITE);
				}
				else {
					UserAccauntVector::accaunts[index].Sebet[i].showinfo();
				}
			}

			cout << "Secmek Ucun Enter: ";

			short kod = _getch();

			if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = UserAccauntVector::accaunts[index].Sebet.size() - 1;
				else {
					color_choice = color_choice;
				}
			}
			else if (kod == DOWN) {
				if (color_choice != UserAccauntVector::accaunts[index].Sebet.size() - 1)
					color_choice++;
				else if (color_choice == UserAccauntVector::accaunts[index].Sebet.size() - 1)
					color_choice = 0;
				else {
					color_choice = color_choice;
				}
			}

			else if (kod == ENTER) {
				Sebet_yemek_menyu(UserAccauntVector::accaunts[index].Sebet[color_choice], index);
			}
			else if (kod == ESC) {
				UserMenyu::menyu(index);
			}
		}


	}

	void Sebet_yemek_menyu(Yemekler& yemek, short index_menyu) {

		system("cls");

		string arry[4] = { "1.Exit:","2.Info:","3.Zakaz","4.Silmek" };

		short color_choice = 0;

		bool davam = true;

		while (davam) {

			system("cls");

			cout << "\t\t\t\t\tYemekZakaz:" << endl;

			yemek.showinfo_full();

			cout << endl;

			for (size_t i = 0; i < 3; i++) {
				if (color_choice == i) {
					change_color(GREEN);
					cout << arry[i] << endl;
					change_color(WHITE);
				}
				else {
					cout << arry[i] << endl;
				}
			}

			cout << "Secmek Ucun Enter: ";

			short kod = _getch();



			if (kod == ESC)
				menyu(index_menyu);
			else if (kod == UP) {
				if (color_choice != 0)
					color_choice--;
				else if (color_choice == 0)
					color_choice = 2;
			}
			else if (kod == DOWN) {
				if (color_choice != 1)
					color_choice++;
				else if (color_choice == 1)
					color_choice = 0;
			}

			else if (kod == ENTER) {
				Yoxlamaq(yemek, color_choice, index_menyu);
			}

		}
	}

	void Yoxlamaq(Yemekler& yemek, int color_choice, short index_menyu) {
		switch (color_choice) {

		case 0:
			menyu(index_menyu);
			break;

		case 1:
			info(yemek, index_menyu);
			break;

		case 2:
			son_zakaz(yemek, color_choice, index_menyu);
			break;

		case 3:
			sebet_silme(yemek, color_choice, index_menyu);
			break;

		default:
			break;
		}
	}

	void info(Yemekler& yemek, short index_menyu) {

		system("cls");

		cout << "\t\t\t\t\tYemekZakaz:" << endl;

		yemek.showinfo_full();

		cout << "Qayitmaq Ucun Istenileni Basin:" << endl;

		short basini_burax = _getch();

		Sebet_yemek_menyu(yemek, index_menyu);
	}

	void sebet_silme(Yemekler& yemek, short index, short index_menyu) {

		system("cls");

		UserAccauntVector::accaunts[index_menyu].Sebet.erase(UserAccauntVector::accaunts[index_menyu].Sebet.begin() + index);

		cout << "Sebetden Uqurla Silindi:";

		Sleep(1400);

		Sebet_yemek_menyu(yemek, index_menyu);

	}

	void son_zakaz(Yemekler& yemek, short index, short index_menyu) {

		system("cls");

		for (size_t a = 0; a < yemek.ingredientleri.size(); a++) {
			for (size_t b = 0; b < IngredientVector::ingredients.size(); b++) {
				if (yemek.ingredientleri[a].getName() == IngredientVector::ingredients[b].getName()) {
					short ambar_say = IngredientVector::ingredients[b].getCount();
					ambar_say -= yemek.ingredientleri[a].getCount();
					IngredientVector::ingredients[b].setCount(ambar_say);
				}
			}
		}

		Gelir_ayliq += yemek.price;
		Gelir_gunluk += yemek.price;
		Bucce += yemek.price;
		UserAccauntVector::accaunts[index_menyu].history.push_back(UserAccauntVector::accaunts[index_menyu].Sebet[index]);

		UserAccauntVector::accaunts[index_menyu].Sebet.erase(UserAccauntVector::accaunts[index_menyu].Sebet.begin() + index);


		cout << "Uqurla Zakaz Olundu:";

		Sleep(1300);

		menyu(index_menyu);

	}
}

#include "UserLoginMenyu.h"

namespace UserLoginMenyu {

	int Console() {

		system("cls");

		vector<string> menyu;

		short color_chocie = 0;

		menyu.push_back("1.Exit");
		menyu.push_back("2.Login");
		menyu.push_back("3.Register");

		while (true) {

			system("cls");

			cout << "\t\t\t\t\t\tLogin Menyu User" << endl;

			for (size_t i = 0; i < menyu.size(); i++) {
				if (i == color_chocie) {
					change_color(GREEN);
					cout << menyu[i] << endl;
					change_color(WHITE);
				}
				else
					cout << menyu[i] << endl;
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
			AccauntCheckUser::Check(UserAccauntVector::accaunts);
		}
		else if (choice == 2) {
		Evvel:
			try {
				UserRegister::Register(UserAccauntVector::accaunts);
			}
			catch (...) {
				system("cls");

				cout << "Xais Olunur Reqem Daxil Edin:";

				Sleep(1500);

				goto Evvel;
			}
		}
	}

	void All() {
		Control(Console());
	}
}

#include "UserHistory.h"

namespace History {
	void history(short index) {

		system("cls");

		if (UserAccauntVector::accaunts[index].history.size() == 0) {
			throw Error("History Yoxdu:");
		}

		cout << "Cixmaq Ucun Esc Basin Eks halda istenileni basin:";

		short kod_ilk = _getch();

		if (kod_ilk == ESC)
			UserMenyu::menyu(index);

		UserAccauntVector::accaunts[index].history;

		for (size_t i = 0; i < UserAccauntVector::accaunts[index].history.size(); i++) {
			UserAccauntVector::accaunts[index].history[i].showinfo();
		}

		cout << "Cixmaq Ucun istenileni basin:" << endl;

		short kod = _getch();

		UserMenyu::menyu(index);
	}
}