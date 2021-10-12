//Програма з власним меню для роботи зі структурними типами даних
/*Програма повинна додавати реквізити квартир в список структур, виводити список руквізитів квартири на екран,
виведення списку квартир вказаної ціни, пошук квартир з мінімальною ціною, пошук вказаної квартири в списку*/
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include "metod.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int quantity = 2; // кількість введених квартир в структуру

	apartment house[10] = { { "Сідоров Заур Данилович", "Карла Маркса", 555, 55, 55000 },
	{ "Семёнов Родион Петрович", "Кіров", 485, 6, 45000 }
	};// количество уже введеных номеров

	int menu_paragraph;
	do
	{
		std::system("cls");
		std::cout << "1. Додавання квартир у список\n";//E ч.1 +
		std::cout << "2. Виведення квартир у список\n";//E ч.2 +
		std::cout << "3. Виведення списку квартир вказаної ціни\n";//D +
		std::cout << "4. Пошук квартир з мінімальною ціною\n";//C +
		std::cout << "5. Пошук вказаної квартири в списку\n";//B +
		std::cout << "6. Вихід\n";



		while (!(std::cin >> menu_paragraph) || (std::cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
		{
			std::system("cls");

			std::cout << "1. Додавання квартир у список\n";
			std::cout << "2. Виведення квартир у список\n";
			std::cout << "3. Виведення списку квартир вказаної ціни\n";
			std::cout << "4. Пошук квартир з мінімальною ціною\n";
			std::cout << "5. Пошук вказаної квартири в списку\n";
			std::cout << "6. Вихід\n";

			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cerr << "Помилка вводу! Ввод номера меню повино бути цілим" << std::endl;
			std::cout << std::endl;
		}
		std::cin.get();//очистка буфера
		switch (menu_paragraph)
		{
		case 1:
			input_apa(quantity, house);
			break;
		case 2:
			output_apa(quantity, house);
			break;
		case 3:
			search_by_price(quantity, house);
			break;
		case 4:
			minimum_price(quantity, house);
			break;
		case 5:
			coincides_apa(quantity, house);
			break;
		case 6:
			return;
			break;
		default:
			break;
		}
	} while (menu_paragraph != 6);
}