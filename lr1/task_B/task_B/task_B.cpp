/*

*/


#include<iostream>
#include<Windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int A, b, c, d, e, f, temp;//temp(��������)
	cout << "������ �������� ������ �����: ";
	cin >> A;

		b = A / 1000;	//����������� ������� ����� 

		temp = A % 1000; 

		c = temp / 100;	//����������� ������� �����

		temp = temp % 100;

		d = temp / 10;//����������� �������� �����

		e = temp % 10;//����������� ���������� �����

		f = (e * 1000) + (d * 100) + (c * 10) + b;	//����������� ����� A �������

		cout << "³������: " << f << endl;


	system("PAUSE");
	return;
}