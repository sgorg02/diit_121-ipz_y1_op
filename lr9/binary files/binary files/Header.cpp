#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Header.h"

int input() {
	int n;
	while (true) {
		system("cls");
		std::cout << "1. ��������� ������� � ������" << std::endl;
		std::cout << "2. ��������� ������� � ������" << std::endl;
		std::cout << "3. ��������� ������ ������� ������� ����" << std::endl;
		std::cout << "4. ����� ������� � ��������� �����" << std::endl;
		std::cout << "5. ����� ������� �������� � ������" << std::endl;
		std::cout << "6. �����" << std::endl;
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
			return n;
	}
}

void input_apa(int &quantity, apartment *house, int sizeOfRecord, char *name) {// ��������� ������� � ������
	std::system("cls");
	long pos;
	apartment one;
	std::cout << "�" << quantity + 1 << std::endl;
	
	std::fstream file(name, std::ios::binary | std::ios::in | std::ios::out);
	
	std::cout << " ������ Բ�: ";
	std::cin.getline(one.name, 50);

	std::cout << " ������ �����: ";
	std::cin.getline(one.built.street, 50);

	std::cout << " ������ ����� �������: ";
	std::cin >> one.built.building;

	std::cout << " ������ ����� ��������: ";
	std::cin >> one.built.number;

	std::cout << " ������ ���� ��������: ";
	std::cin >> one.price;


	file.seekg(quantity * static_cast<double> (sizeOfRecord), std::ios::beg);	//set to fourth record
	pos = file.tellg();
	file.seekp(pos, std::ios::beg);
	file.write(reinterpret_cast<char*>(&one), sizeOfRecord);
	quantity++;
	file.close();
	system("pause");
}

void show_list(int& quantity, int sizeOfRecord, char *name) {// ���� ������ ��� �������
	system("cls");
	std::ifstream in(name, std::ios::binary | std::ios::in);
	apartment tmp_house;
	in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !in.eof(); i++) {
		std::cout << "�" << i + 1 << std::endl;
		std::cout << " Բ�: " << tmp_house.name << std::endl;
		std::cout << " �����: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
		std::cout << " ֳ��: " << tmp_house.price << std::endl << std::endl;
		in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	
	system("pause");
	in.close();
}

void search_by_price(int quantity, int sizeOfRecord, char *name) {// ��������� ������ ������� ������� ����
	std::system("cls");
	int search_price;
	bool find = false;
	apartment tmp_house;
	std::ifstream file(name, std::ios::binary | std::ios::in);

	std::cout << "������ ���� ��������: ";
	std::cin >> search_price;
	std::cin.get(); // ������� ������

	file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !file.eof(); i++) {
		if (search_price == tmp_house.price) {
			std::cout << "�" << i + 1 << std::endl;
			std::cout << " Բ�: " << tmp_house.name << std::endl;
			std::cout << " �����: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
			std::cout << " ֳ��: " << tmp_house.price << std::endl << std::endl;
			find = true;
		}
		file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}

	if (!find)
		std::cout << "�� �������� � ������ ������� � ����� �����!" << std::endl << std::endl;
	file.close();
	system("pause");
}

void minimum_price(int quantity, int sizeOfRecord, char *name){// ����� ������� � ��������� �����
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
			std::cout << "�" << i + 1 << std::endl;
			std::cout << " Բ�: " << tmp_house.name << std::endl;
			std::cout << " �����: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
			std::cout << " ֳ��: " << tmp_house.price << std::endl << std::endl;
		}
		in.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	in.close();
	system("pause");
}

void coincides_apa(int sizeOfRecord, char *name){// ����� ������� �������� � ������
	std::system("cls");
	bool find = true;
	apartment tmp_house, comparison_house;
	std::ifstream file(name, std::ios::binary | std::ios::in);
	
	std::cout << "������ Բ�: ";
	std::cin.getline(comparison_house.name, 50);

	std::cout << "������ �����: ";
	std::cin.getline(comparison_house.built.street, 50);

	std::cout << "������ ����� �������: ";
	std::cin >> comparison_house.built.building;

	std::cout << "������ ����� ��������: ";
	std::cin >> comparison_house.built.number;

	std::cout << "������ ���� ��������: ";
	std::cin >> comparison_house.price;
	file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	for (int i = 0; !file.eof(); i++) {
		if (strcmp(comparison_house.name, tmp_house.name) == 0) {
			if (strcmp(comparison_house.built.street, tmp_house.built.street) == 0) {
				if (comparison_house.built.building == tmp_house.built.building) {
					if (comparison_house.built.number == tmp_house.built.number) {
						if (comparison_house.price == tmp_house.price) {
							std::cout << std::endl << "�������� � ������ ���������� � � ������." << std::endl;
							std::cout << "�" << i + 1 << std::endl;
							std::cout << " Բ�: " << tmp_house.name << std::endl;
							std::cout << " �����: " << tmp_house.built.street << ", " << tmp_house.built.building << ", " << tmp_house.built.number << std::endl;
							std::cout << " ֳ��: " << tmp_house.price << std::endl << std::endl;
							find = false;
						}
					}
				}
			}
		}
		file.read(reinterpret_cast<char*>(&tmp_house), sizeOfRecord);
	}
	if (find)
		std::cout << std::endl << "�� �� �������� � ������!" << std::endl;
	system("pause");
}