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
	float* items;
	int* temp;
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
	
	

	int size;//����� ������
	size = arr.rows * arr.cols;

	arr.items = new float[size];
	arr.temp = new int[size];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < size; ++i)
	{
		arr.items[i] = static_cast <float>((rand()) % static_cast <int>((max - min) * 100)) / 100 + min;
	}
	
	std::cout << std::endl;
	std::cout << "����� ���������� �����:" << std::endl;
	for (int i = 0, k = 0; i < arr.rows; i++) 
	{
		for (int j = 0; j < arr.cols; j++, k++) 
		{
			std::cout << arr.items[k] << "\t";
		}
		std::cout << std::endl;
	}


	//////////////////////////////

	// �������� E

	for (int i = 0; i < size; i++)
	{
		arr.temp[i] = arr.items[i];
		//std::cout << arr.temp[i] << " ";
		if (arr.temp[i] % 2)
		{
			quantity++;
		}
	}
	std::cout << std::endl;
	std::cout << "ʳ������ �������� �������, � ���� ���� ������� � �������� ������: " << quantity << std::endl;
	std::cout << std::endl;


	//////////////////////////////
	
	// �������� D
	
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		arr.temp[i] = arr.items[i];
		//std::cout << arr.temp[i] << " ";
		if ((arr.temp[i] < 0) && (arr.temp[i] >= -2))
		{		
			sum = sum + arr.temp[i];
		}
	}
	std::cout << "C��� �䒺���� �������� �������, � ���� ����� � ������ ������� �� �������� 2: " << sum << std::endl; // ����� ��������� ���� -
	std::cout << std::endl;
	
	
	//////////////////////////////
	
	// �������� C

	int* Arr;
	Arr = new int[arr.rows];// ���������� ������ ��� ���� ������� ����� 
	
	int k = 1;
	sum = 0;
	for (int i = 0, j = 0; i < size; i++, k++)
	{

		arr.temp[i] = arr.items[i];
		//std::cout << arr.temp[i] << " ";
		if ((arr.temp[i] < 0) && (arr.temp[i] >= -2))
		{
			sum = sum + arr.temp[i];
		}

		if (k == arr.cols)
		{
			Arr[j] = sum; // ����� ��������� ���� -
			sum = 0;
			k = 0;
			j++;
		}
		//cout << endl;
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