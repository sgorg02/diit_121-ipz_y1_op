/*

*/

#include<iostream>
#include<Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double a, b, x;// x(в≥дпов≥дь)

	cout << "¬вед≥ть число а: ";
	cin >> a;

	cout << "¬вед≥ть число в: ";
	cin >> b;

	x = (7 * 7 * 7 * a) - (2 * b);
	cout << "¬≥дпов≥дь: " << x << endl;


	system("pause");
	return;

}