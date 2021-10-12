/* Вариант 9
Реалізувати заповнення масиву випадковими числами.
З елементів масива робимо наступні дії:
- кількість елементів матриці, у яких ціла частина є непарним числом
- сума від’ємних елементів матриці, в яких цифра в розряді одиниць не перевищує 2
- результати обчислення суми від’ємних елементів матриці в рядку, які записані в масив
- відсортувати рядки матриці за зростанням (непарний варіант)  відповідних елементів масиву, створеного у п.С.
- видалити з матриці рядки, в яких перший елемент менше другого елементу
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
	int quantity = 0; //лічильник


					  //ввод та перевірка розміра матриці
	std::cout << "Введіть кількість рядків матриці:  ";
	while (!(std::cin >> arr.rows) || (std::cin.peek() != '\n') || !(arr.rows > 1)) // цикл для перевірки введеної зміної на символи
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		system("cls");
		std::cerr << "Помилка вводу! Повторіть ввод. Кількість рядків повино бути цілим числом та більше одиниці." << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть кількість рядків матриці: ";
	}

	std::cout << "Введіть кількість стовпців матриці:  ";
	while (!(std::cin >> arr.cols) || (std::cin.peek() != '\n') || !(arr.cols > 1)) // цикл для перевірки введеної зміної на символи
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		system("cls");
		std::cerr << "Помилка вводу! Повторіть ввод. Кількість стовпців повино бути цілим числом та більше одиниці." << std::endl;
		std::cout << std::endl;
		std::cout << "Введіть кількість стовпців матриці: ";
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
	std::cout << "Масив випадкових чисел:" << std::endl;
	for (int i = 0; i < arr.rows; i++)
	{
		for (int j = 0; j < arr.cols; j++)
		{
			std::cout << arr.items[i][j] << "\t";
		}
		std::cout << std::endl;
	}


	//////////////////////////////

	// завдання E

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
	std::cout << "Кількість елементів матриці, у яких ціла частина є непарним числом: " << quantity << std::endl;
	std::cout << std::endl;


	//////////////////////////////

	// завдання D

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
	std::cout << "Cума від’ємних елементів матриці, в яких цифра в розряді одиниць не перевищує 2: " << sum << std::endl; // можно поставити знак -
	std::cout << std::endl;


	//////////////////////////////

	// завдання C

	int* Arr;
	Arr = new int[arr.rows];// створенння масиву для суми кожного рядка 


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
		Arr[i] = sum; // можно поставити знак -
		sum = 0;
	}


	std::cout << "Результати обчислення суми від’ємних елементів матриці в рядку, які записані в масив: " << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < arr.rows; i++)
	{
		std::cout << Arr[i] << "\t"; // можно поставити знак -
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