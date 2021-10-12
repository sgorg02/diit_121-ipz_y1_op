#include <iostream>
#include<Windows.h>
#include <cstdlib>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int rows, cols;


	cout << "Введіть розмір матриці =  ";
	while (!(cin >> rows) || (cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "Помилка вводу! Повторить ввод. n повино бути цілим" << endl;
		cout << endl;
		cout << "Введіть розмір матриці = ";
	}

	while (!(rows > 1) || (cin.peek() != '\n')) // цикл для перевірки введеної зміної розмір
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "Розмір матриці повинен бути більше одного елемента!" << endl;
		cout << endl;
		cout << "Введіть розмір матриці = ";
		cin >> rows;
	}

	cols = rows;

	int** arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	// Заповнення значень масива

	for (int i = 0; i < rows; i++)
	{
		cout << "Введіть " << i + 1 << " рядок матриці = " << endl;
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}

	// Вивід значень масива

	cout << "\tЗагальній вид матриці" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	// Дії над елементами головної діагоналі матриці
 
	for (int i = 0; i < rows; i++)
	{
			if (arr[i][i] > 0) // перевірка елементів головної діагоналі (елелмент > 0)
			{
				int max = arr[i][0];
				for (int j = 1; j < cols; j++)
				{
					if (max > arr[i][j])
					{
						//cout << "Найбольшое число " << max << endl;
					}
					else
					{
						max = arr[i][j];
					}
				}
				cout << "Так як в рядку " << i + 1 << " є додатній елемент головної матриці найболільше число " << max << endl;
				cout << endl;
			}
			else if (arr[i][i] < 0) // перевірка елементів головної діагоналі (елелмент < 0)
			{
				int sum = 0;
				for (int j = 0; j < cols; j++)
				{
					sum = sum + arr[i][j];
				}
				cout << "Так як в рядку " << i + 1 << " є відємним елемент головної матриці сума рядка " << sum << endl;
				cout << endl;
			}
			else
			{
				cout << "В рядку " << i + 1 << " елемент головної діагоналі рівен 0" << endl;
				cout << endl;
			}
		}

		///////////////////////////////
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;



		system("pause");
		return;

}