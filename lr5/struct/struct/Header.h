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

apartment house[10] = { { "Сідоров Заур Данилович", "Карла Маркса", 555, 55, 55000 },
{ "Семёнов Родион Петрович", "Москва", 485, 6, 45000 }
};

void input_apa()
{
	std::system("cls");

	std::cout << "Номер квартири у списку: " << quantity + 1 << std::endl;

	std::cout << "Введіть ФІО: ";
	std::cin.getline(house[quantity].name, 50);


	std::cout << "Введіть адрес: ";
	std::cin.getline(house[quantity].built.street, 50);


	std::cout << "Введіть номер будинка: ";
	std::cin >> house[quantity].built.building;

	std::cout << "Введіть номер квартири: ";
	std::cin >> house[quantity].built.number;

	std::cout << "Введіть ціну квартири: ";
	std::cin >> house[quantity].price;

	quantity++;
}

void output_apa()
{
	std::system("cls");

	for (int i = 0; i < quantity; i++)
	{

		std::cout << "№:" << i + 1 << std::endl;
		std::cout << " ФІО: " << house[i].name << std::endl;
		std::cout << " Адрес: " << house[i].built.street << ", " << house[i].built.building << ", " << house[i].built.number << std::endl;
		std::cout << " Ціна: " << house[i].price << std::endl << std::endl;
	}

	system("pause");
}

void search_by_price()
{
	std::system("cls");

	int search_price;
	bool find = false;
	std::cout << "Введіть ціну квартири: ";
	std::cin >> search_price;
	std::cin.get(); // очистка буфера
	for (int i = 0; i < quantity; i++)
	{
		if (search_price == house[i].price)
		{
			std::cout << "№:" << i + 1 << std::endl;
			std::cout << " ФІО: " << house[i].name << std::endl;
			std::cout << " Адрес: " << house[i].built.street << ", " << house[i].built.building << ", " << house[i].built.number << std::endl;
			std::cout << " Ціна: " << house[i].price << std::endl << std::endl;
			find = true;
			system("pause");
		}
	}

	if (!find)
	{
		std::cout << "Не знайдено в списку кватири з такою ціною!" << std::endl;
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
			//std::cout << "Найменьша ціна " << min_price << std::endl;
		}
		else
		{
			min_price = house[i].price;
		}
	}
	//std::cout << "Мнинимум " << min_price << std::endl;

	for (int i = 0; i < quantity; i++)
	{
		if (min_price == house[i].price)
		{
			std::cout << "№:" << i + 1 << std::endl;
			std::cout << " ФІО: " << house[i].name << std::endl;
			std::cout << " Адрес: " << house[i].built.street << ", " << house[i].built.building << ", " << house[i].built.number << std::endl;
			std::cout << " Ціна: " << house[i].price << std::endl << std::endl;
		}
	}

	system("pause");
}

void coincides_apa()
{
	std::system("cls");

	char name_[50];
	std::cout << "Введіть ФІО: ";
	std::cin.getline(name_, 50);

	char street_[50];
	std::cout << "Введіть адрес: ";
	std::cin.getline(street_, 50);

	int building_;
	std::cout << "Введіть номер будинка: ";
	std::cin >> building_;

	int number_;
	std::cout << "Введіть номер квартири: ";
	std::cin >> number_;

	int price_;
	std::cout << "Введіть ціну квартири: ";
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
							std::cout << std::endl << "Квартира с такими реквізитами є у списку." << std::endl;
							std::cout << std::endl;
							system("pause");
							find = true;
						}
						else
						{
							std::cout << "Не має квартири в списку. Можливо ви помилилися з ціню!" << std::endl;
						}
					}
					else
					{
						std::cout << "Не має квартири в списку. Можливо ви помилилися з номером квартири!" << std::endl;
					}
				}
				else
				{
					std::cout << "Не має квартири в списку. Можливо ви помилилися з номером будинка!" << std::endl;
				}
			}
			else
			{
				std::cout << "Не має квартири в списку. Можливо ви помилилися з вулицею!" << std::endl;
			}
		}
		else
		{
			std::cout << "Не має квартири в списку. Можливо ви помилилися з ініціалами!" << std::endl;
		}
	}
	//system("pause");
}