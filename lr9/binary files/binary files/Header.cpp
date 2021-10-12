#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Header.h"

int input() {
	int n;
	while (true) {
		system("cls");
		std::cout << "1. Додавання квартир у список" << std::endl;
		std::cout << "2. Виведення квартир у список" << std::endl;
		std::cout << "3. Виведення списку квартир вказаної ціни" << std::endl;
		std::cout << "4. Пошук квартир з мінімальною ціною" << std::endl;
		std::cout << "5. Пошук вказаної квартири в списку" << std::endl;
		std::cout << "6. Выход" << std::endl;
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
			return n;
	}
}

void input_apa(int &quantity, apartment *house, int sizeOfRecord, char *name) {// додавання квартир в список
	std::system("cls");
	long pos;
	apartment one;
	std::cout << "№" << quantity + 1 << std::endl;
	
	std::fstream file(name, std::ios::binary | std::ios::in | std::ios::out);
	
	std::cout << " Введіть ФІО: ";
	std::cin.getline(one.name, 50);

	std::cout << " Введіть адрес: ";
	std::cin.getline(one.built.street, 50);

	std::cout << " Введіть номер будинка: ";
	std::cin >> one.built.building;

	std::cout << " Введіть номер квартири: ";
	std::cin >> one.built.number;

	std::cout << " Введіть ціну квартири: ";
	std::cin >> one.price;


	file.seekg(quantity * static_cast<double> (sizeOfRecord), std::ios::beg);	//set to fourth record
	pos = file.tellg();
	file.seekp(pos, std::ios::beg);
	file.write(reinterpret_cast<char*>(&one), sizeOfRecord);
	quantity++;
	file.close();
	system("pause");
}

void show_list(int& quantity, int sizeOfRecord, char *name) {// вивід списку всіх квартир
	system("cls");
	std::ifstream in(name, std::ios::binary | std::ios::in);
	apartment tmp_house;
	in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !in.eof(); i++) {
		std::cout << "№" << i + 1 << std::endl;
		std::cout << " ФІО: " << tmp_house.name << std::endl;
		std::cout << " Адрес: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
		std::cout << " Ціна: " << tmp_house.price << std::endl << std::endl;
		in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	
	system("pause");
	in.close();
}

void search_by_price(int quantity, int sizeOfRecord, char *name) {// Виведення списку квартир вказаної ціни
	std::system("cls");
	int search_price;
	bool find = false;
	apartment tmp_house;
	std::ifstream file(name, std::ios::binary | std::ios::in);

	std::cout << "Введіть ціну квартири: ";
	std::cin >> search_price;
	std::cin.get(); // очистка буфера

	file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !file.eof(); i++) {
		if (search_price == tmp_house.price) {
			std::cout << "№" << i + 1 << std::endl;
			std::cout << " ФІО: " << tmp_house.name << std::endl;
			std::cout << " Адрес: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
			std::cout << " Ціна: " << tmp_house.price << std::endl << std::endl;
			find = true;
		}
		file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}

	if (!find)
		std::cout << "Не знайдено в списку кватири з такою ціною!" << std::endl << std::endl;
	file.close();
	system("pause");
}

void minimum_price(int quantity, int sizeOfRecord, char *name){// Пошук квартир з мінімальною ціною
	std::system("cls");
	int min_price;
	apartment tmp_house;
	std::ifstream file(name, std::ios::binary | std::ios::in);

	file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	min_price = tmp_house.price;
	while (!file.eof()) {
		if (min_price < tmp_house.price) {}
		else
			min_price = tmp_house.price;
		file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	file.close();

	std::ifstream in(name, std::ios::binary | std::ios::in);
	in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !in.eof(); i++) {
		if (min_price == tmp_house.price) {
			std::cout << "№" << i + 1 << std::endl;
			std::cout << " ФІО: " << tmp_house.name << std::endl;
			std::cout << " Адрес: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
			std::cout << " Ціна: " << tmp_house.price << std::endl << std::endl;
		}
		in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	in.close();
	system("pause");
}

void coincides_apa(int sizeOfRecord, char *name){// Пошук вказаної квартири в списку
	std::system("cls");
	bool find = true;
	apartment tmp_house, comparison_house;
	std::ifstream file(name, std::ios::binary | std::ios::in);
	
	std::cout << "Введіть ФІО: ";
	std::cin.getline(comparison_house.name, 50);

	std::cout << "Введіть адрес: ";
	std::cin.getline(comparison_house.built.street, 50);

	std::cout << "Введіть номер будинка: ";
	std::cin >> comparison_house.built.building;

	std::cout << "Введіть номер квартири: ";
	std::cin >> comparison_house.built.number;

	std::cout << "Введіть ціну квартири: ";
	std::cin >> comparison_house.price;
	file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !file.eof(); i++) {
		if (strcmp(comparison_house.name, tmp_house.name) == 0) {
			if (strcmp(comparison_house.built.street, tmp_house.built.street) == 0) {
				if (comparison_house.built.building == tmp_house.built.building) {
					if (comparison_house.built.number == tmp_house.built.number) {
						if (comparison_house.price == tmp_house.price) {
							std::cout << std::endl << "Квартира с такими реквізитами є у списку." << std::endl;
							std::cout << "№" << i + 1 << std::endl;
							std::cout << " ФІО: " << tmp_house.name << std::endl;
							std::cout << " Адрес: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
							std::cout << " Ціна: " << tmp_house.price << std::endl << std::endl;
							find = false;
						}
					}
				}
			}
		}
		file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	if (find)
		std::cout << std::endl << "Не має квартири в списку!" << std::endl;
	system("pause");
}