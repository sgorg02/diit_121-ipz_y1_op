/* ������� 9
���������� ���������� ������ ����������� �������.
� �������� ������ ������ ������� 䳿:
- ������� �������� �������, � ���� ���� ������� � �������� ������
- ���� �䒺���� �������� �������, � ���� ����� � ������ ������� �� �������� 2
- ���������� ���������� ���� �䒺���� �������� ������� � �����, �� ������� � �����
- ����������� ����� ������� �� ���������� (�������� ������)  ��������� �������� ������, ���������� � �.�.
- �������� � ������� �����, � ���� ������ ������� ����� ������� ��������
*/
#include <iostream>
#include <Windows.h>
#include <ctime>


struct Matrix {
	int rows;
	int cols;
	float** items;
	int** temp;
};

const float min = -22.20;
const float max = 10.25;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Matrix arr;
	int quantity = 0; //��������


					  //���� �� �������� ������ �������
	std::cout << "������ ������� ����� �������:  ";
	while (!(std::cin >> arr.rows) || (std::cin.peek() != '\n') || !(arr.rows > 1)) // ���� ��� �������� ������� ���� �� �������
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		system("cls");
		std::cerr << "������� �����! �������� ����. ʳ������ ����� ������ ���� ����� ������ �� ����� �������." << std::endl;
		std::cout << std::endl;
		std::cout << "������ ������� ����� �������: ";
	}

	std::cout << "������ ������� �������� �������:  ";
	while (!(std::cin >> arr.cols) || (std::cin.peek() != '\n') || !(arr.cols > 1)) // ���� ��� �������� ������� ���� �� �������
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		system("cls");
		std::cerr << "������� �����! �������� ����. ʳ������ �������� ������ ���� ����� ������ �� ����� �������." << std::endl;
		std::cout << std::endl;
		std::cout << "������ ������� �������� �������: ";
	}




	arr.items = new float *[arr.rows];
	for (int i = 0; i < arr.rows; i++)
	{
		arr.items[i] = new float[arr.cols];
	}


	
	arr.temp = new int *[arr.rows];
	for (int i = 0; i < arr.rows; i++)
	{
		arr.temp[i] = new int[arr.cols];
	}

	srand((unsigned int)time(NULL));

	for (int i = 0; i < arr.rows; ++i)
	{
		for (int j = 0; j < arr.cols; ++j)
		{
			arr.items[i][j] = static_cast <float>((rand()) % static_cast <int>((max - min) * 100)) / 100 + min;
		}
	}

	std::cout << std::endl;
	std::cout << "����� ���������� �����:" << std::endl;
	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			std::cout << arr.items[i][j] << "\t";
		}
		std::cout << std::endl;
	}


	//////////////////////////////

	// �������� E

	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			arr.temp[i][j] = arr.items[i][j];
			//std::cout << arr.temp[i] << " ";
			if (arr.temp[i][j] % 2)
			{
				quantity++;
			}
		}
	}
	std::cout << std::endl;
	std::cout << "ʳ������ �������� �������, � ���� ���� ������� � �������� ������: " << quantity << std::endl;
	std::cout << std::endl;


	//////////////////////////////

	// �������� D

	int sum = 0;
	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			arr.temp[i][j] = arr.items[i][j];
			//std::cout << arr.temp[i] << " ";
			if ((arr.temp[i][j] < 0) && (arr.temp[i][j] >= -2))
			{
				sum = sum + arr.temp[i][j];
			}
		}
	}
	std::cout << "C��� �䒺���� �������� �������, � ���� ����� � ������ ������� �� �������� 2: " << sum << std::endl; // ����� ��������� ���� -
	std::cout << std::endl;


	//////////////////////////////

	// �������� C

	int* Arr;
	Arr = new int[arr.rows];// ���������� ������ ��� ���� ������� ����� 


	sum = 0;
	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			arr.temp[i][j] = arr.items[i][j];
			//std::cout << arr.temp[i] << " ";
			if ((arr.temp[i][j] < 0) && (arr.temp[i][j] >= -2))
			{
				sum = sum + arr.temp[i][j];
			}
		}
		Arr[i] = sum; // ����� ��������� ���� -
		sum = 0;
	}


	std::cout << "���������� ���������� ���� �䒺���� �������� ������� � �����, �� ������� � �����: " << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < arr.rows; i++)
	{
		std::cout << Arr[i] << "\t"; // ����� ��������� ���� -
									 //cout << endl;
	}
	std::cout << std::endl;

	//////////////////////////////


	delete[]Arr;
	delete[]arr.items;
	delete[]arr.temp;

	system("pause");
	return 0;

}