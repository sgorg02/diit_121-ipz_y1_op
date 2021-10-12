/*
Заданими правилами за допомогою циклу знайти v ти u
*/


#include<iostream>
#include<Windows.h>
using namespace std;


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double V_result, u_result;
	double v1 = 0, v2 = 1, u1 = 1, u2 = 2;
	int n;

	cout << "Введіть n = ";
	while (!(cin >> n) || (cin.peek() != '\n')) // цикл для перевірки введеної зміної на символи
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "Помилка вводу! Повторить ввод. n повино бути цілим" << endl;
		cout << "Введіть n = ";
	}


	while ((n < 3) || (cin.peek() != '\n')) // цикл для перевірки правила на границю числа 
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "! Число n повино бути більше 2" << endl;
		cout << "Введіть n = ";
		cin >> n;
	}


		int i = 3;
		do
		{
			u_result = u2 - (u1 * v2) - v1;
			V_result = u2 - v2;
			cout << "Відповідь V" << i << " = " << V_result << endl; // цей блок для виведення реулитату кожного кола
			//cout << "Відповідь u" << i << " = " << u_result << endl;
			u1 = u2;
			v1 = v2;
			u2 = u_result;
			v2 = V_result;
			--n;
		} while (i <= n);

		/*cout << " Відповідь V = " << V_result << endl;  // цей блок зроблен для виведення результату кінцевого
		cout << " Відповідь u = " << u_result << endl;*/
	


	system("pause");
	return;
}