#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Header.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int quantity = 2;
	int  menu_choice;
	int sizeOfRecord = sizeof apartment;
	char name[20];

	apartment house[2] = { { "Сідоров Заур Данилович", "Карла Маркса", 555, 55, 55000 },
	{ "Семёнов Родион Петрович", "Кіров", 485, 6, 45000 }
	};

	std::cout << "Введіть назву файла: ";
	std::cin >> name;
	std::ofstream file(name, std::ios::binary | std::ios::out | std::ios::trunc);
	file.write(reinterpret_cast<char*>(house), sizeof house);
	file.close();

	do {
		menu_choice = input();

		switch (menu_choice) {
		case 1:
			std::cin.get();
			input_apa(quantity, house, sizeOfRecord, name);
			break;
		case 2:
			show_list(quantity, sizeOfRecord, name);
			break;
		case 3:
			search_by_price(quantity, sizeOfRecord, name);
			break;
		case 4:
			minimum_price(quantity, sizeOfRecord, name);
			break;
		case 5:
			std::cin.get();
			coincides_apa(sizeOfRecord, name);
			break;
		case 6:
			return 0;
			break;
		default:
			break;
		}
	} while (menu_choice != 6);
}