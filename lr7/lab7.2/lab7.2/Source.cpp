//�������� � ������� ���� ��� ������ � ������������ ������ �����
/*�������� ������� �������� �������� ������� � ������ ��������, �������� ������ �������� �������� �� �����,
��������� ������ ������� ������� ����, ����� ������� � ��������� �����, ����� ������� �������� � ������*/
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include "metod.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int quantity = 2; // ������� �������� ������� � ���������

	apartment house[10] = { { "ѳ����� ���� ���������", "����� ������", 555, 55, 55000 },
	{ "������ ������ ��������", "ʳ���", 485, 6, 45000 }
	};// ���������� ��� �������� �������

	int menu_paragraph;
	do
	{
		std::system("cls");
		std::cout << "1. ��������� ������� � ������\n";//E �.1 +
		std::cout << "2. ��������� ������� � ������\n";//E �.2 +
		std::cout << "3. ��������� ������ ������� ������� ����\n";//D +
		std::cout << "4. ����� ������� � ��������� �����\n";//C +
		std::cout << "5. ����� ������� �������� � ������\n";//B +
		std::cout << "6. �����\n";



		while (!(std::cin >> menu_paragraph) || (std::cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
		{
			std::system("cls");

			std::cout << "1. ��������� ������� � ������\n";
			std::cout << "2. ��������� ������� � ������\n";
			std::cout << "3. ��������� ������ ������� ������� ����\n";
			std::cout << "4. ����� ������� � ��������� �����\n";
			std::cout << "5. ����� ������� �������� � ������\n";
			std::cout << "6. �����\n";

			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cerr << "������� �����! ���� ������ ���� ������ ���� �����" << std::endl;
			std::cout << std::endl;
		}
		std::cin.get();//������� ������
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