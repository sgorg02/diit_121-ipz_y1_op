/*

*/

#include<iostream>
#include<Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a, b, x;// x(�������)

	cout << "������ ����� �: ";
	cin >> a;

	cout << "������ ����� �: ";
	cin >> b;

	x = (7 * 7 * 7 * a) - (2 * b);
	cout << "³������: " << x << endl;


	system("pause");
	return;

}