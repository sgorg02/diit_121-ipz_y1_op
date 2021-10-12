#include <iostream>
#include <windows.h>
#pragma once

struct address {
	char street[50];
	int building;
	int number;
};


struct apartment {
	char name[50];
	address built;
	int price;

};

int quantity = 2;

apartment house[10] = { { "ѳ����� ���� ���������", "����� ������", 555, 55, 55000 },
{ "������ ������ ��������", "������", 485, 6, 45000 }
};

void input_apa()
{
	std::system("cls");

	std::cout << "����� �������� � ������: " << quantity + 1 << std::endl;

	std::cout << "������ Բ�: ";
	std::cin.getline(house[quantity].name, 50);


	std::cout << "������ �����: ";
	std::cin.getline(house[quantity].built.street, 50);


	std::cout << "������ ����� �������: ";
	std::cin >> house[quantity].built.building;

	std::cout << "������ ����� ��������: ";
	std::cin >> house[quantity].built.number;

	std::cout << "������ ���� ��������: ";
	std::cin >> house[quantity].price;

	quantity++;
}

void output_apa()
{
	std::system("cls");

	for (int i = 0; i < quantity; i++)
	{

		std::cout << "�:" << i + 1 << std::endl;
		std::cout << " Բ�: " << house[i].name << std::endl;
		std::cout << " �����: " << house[i].built.street << ", " << house[i].built.building << ", " << house[i].built.number << std::endl;
		std::cout << " ֳ��: " << house[i].price << std::endl << std::endl;
	}

	system("pause");
}

void search_by_price()
{
	std::system("cls");

	int search_price;
	bool find = false;
	std::cout << "������ ���� ��������: ";
	std::cin >> search_price;
	std::cin.get(); // ������� ������
	for (int i = 0; i < quantity; i++)
	{
		if (search_price == house[i].price)
		{
			std::cout << "�:" << i + 1 << std::endl;
			std::cout << " Բ�: " << house[i].name << std::endl;
			std::cout << " �����: " << house[i].built.street << ", " << house[i].built.building << ", " << house[i].built.number << std::endl;
			std::cout << " ֳ��: " << house[i].price << std::endl << std::endl;
			find = true;
			system("pause");
		}
	}

	if (!find)
	{
		std::cout << "�� �������� � ������ ������� � ����� �����!" << std::endl;
		std::cout << std::endl;
		system("pause");
	}
}

void minimum_price()
{
	std::system("cls");

	int min_price = house[0].price;
	for (int i = 1; i < quantity; i++)
	{
		if (min_price < house[i].price)
		{
			//std::cout << "��������� ���� " << min_price << std::endl;
		}
		else
		{
			min_price = house[i].price;
		}
	}
	//std::cout << "�������� " << min_price << std::endl;

	for (int i = 0; i < quantity; i++)
	{
		if (min_price == house[i].price)
		{
			std::cout << "�:" << i + 1 << std::endl;
			std::cout << " Բ�: " << house[i].name << std::endl;
			std::cout << " �����: " << house[i].built.street << ", " << house[i].built.building << ", " << house[i].built.number << std::endl;
			std::cout << " ֳ��: " << house[i].price << std::endl << std::endl;
		}
	}

	system("pause");
}

void coincides_apa()
{
	std::system("cls");

	char name_[50];
	std::cout << "������ Բ�: ";
	std::cin.getline(name_, 50);

	char street_[50];
	std::cout << "������ �����: ";
	std::cin.getline(street_, 50);

	int building_;
	std::cout << "������ ����� �������: ";
	std::cin >> building_;

	int number_;
	std::cout << "������ ����� ��������: ";
	std::cin >> number_;

	int price_;
	std::cout << "������ ���� ��������: ";
	std::cin >> price_;

	bool find = false;
	for (int i = 0; !(find) && i < quantity; i++)
	{
		if (strcmp(name_, house[i].name) == 0)
		{
			if (strcmp(street_, house[i].built.street) == 0)
			{
				if (building_ == house[i].built.building)
				{
					if (number_ == house[i].built.number)
					{
						if (price_ == house[i].price)
						{
							std::cout << std::endl << "�������� � ������ ���������� � � ������." << std::endl;
							std::cout << std::endl;
							system("pause");
							find = true;
						}
						else
						{
							std::cout << "�� �� �������� � ������. ������� �� ���������� � ����!" << std::endl;
						}
					}
					else
					{
						std::cout << "�� �� �������� � ������. ������� �� ���������� � ������� ��������!" << std::endl;
					}
				}
				else
				{
					std::cout << "�� �� �������� � ������. ������� �� ���������� � ������� �������!" << std::endl;
				}
			}
			else
			{
				std::cout << "�� �� �������� � ������. ������� �� ���������� � �������!" << std::endl;
			}
		}
		else
		{
			std::cout << "�� �� �������� � ������. ������� �� ���������� � ���������!" << std::endl;
		}
	}
	//system("pause");
}