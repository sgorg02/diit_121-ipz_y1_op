#include <iostream>
#include<Windows.h>
#include <cstdlib>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int rows, cols;


	cout << "������ ����� ������� =  ";
	while (!(cin >> rows) || (cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "������� �����! ��������� ����. n ������ ���� �����" << endl;
		cout << endl;
		cout << "������ ����� ������� = ";
	}

	while (!(rows > 1) || (cin.peek() != '\n')) // ���� ��� �������� ������� ���� �����
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "����� ������� ������� ���� ����� ������ ��������!" << endl;
		cout << endl;
		cout << "������ ����� ������� = ";
		cin >> rows;
	}

	cols = rows;

	int** arr = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	// ���������� ������� ������

	for (int i = 0; i < rows; i++)
	{
		cout << "������ " << i + 1 << " ����� ������� = " << endl;
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}

	// ���� ������� ������

	cout << "\t�������� ��� �������" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "\t" << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	// ĳ� ��� ���������� ������� ������� �������
 
	for (int i = 0; i < rows; i++)
	{
			if (arr[i][i] > 0) // �������� �������� ������� ������� (�������� > 0)
			{
				int max = arr[i][0];
				for (int j = 1; j < cols; j++)
				{
					if (max > arr[i][j])
					{
						//cout << "���������� ����� " << max << endl;
					}
					else
					{
						max = arr[i][j];
					}
				}
				cout << "��� �� � ����� " << i + 1 << " � ������� ������� ������� ������� ���������� ����� " << max << endl;
				cout << endl;
			}
			else if (arr[i][i] < 0) // �������� �������� ������� ������� (�������� < 0)
			{
				int sum = 0;
				for (int j = 0; j < cols; j++)
				{
					sum = sum + arr[i][j];
				}
				cout << "��� �� � ����� " << i + 1 << " � ������ ������� ������� ������� ���� ����� " << sum << endl;
				cout << endl;
			}
			else
			{
				cout << "� ����� " << i + 1 << " ������� ������� ������� ���� 0" << endl;
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