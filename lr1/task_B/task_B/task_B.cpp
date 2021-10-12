/*

*/


#include<iostream>
#include<Windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int A, b, c, d, e, f, temp;//temp(временая)
	cout << "Введіть чотирьох значне число: ";
	cin >> A;

		b = A / 1000;	//знаходження першого число 

		temp = A % 1000; 

		c = temp / 100;	//знаходження другого числа

		temp = temp % 100;

		d = temp / 10;//знаходження третього числа

		e = temp % 10;//знаходження четвертого число

		f = (e * 1000) + (d * 100) + (c * 10) + b;	//знаходження числа A навпаки

		cout << "Відповідь: " << f << endl;


	system("PAUSE");
	return;
}