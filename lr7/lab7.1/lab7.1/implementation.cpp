#include <iostream>
#include "Windows.h"
#include "metod.h"


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	///////////////////////////////////////

	int x = 10;
	char ch1 = (43);
	bool question = true;

	std::cout << std::endl;
	std::cout << "До виклика: " << x << '\t' << ch1 << '\t' << question << std::endl;
	int n = f1(10, 43, question);
	std::cout << "Функція 1 повертає значення int: " << n << std::endl;
	std::cout << "Після виклика: " << x << '\t' << ch1 << '\t' << question << std::endl << std::endl;


	std::cout << std::endl;
	std::cout << "До виклика: " << x << '\t' << ch1 << '\t' << question << std::endl;
	char ch = f2(x, ch1, question);
	std::cout << "Функція 2 повертає значення char: " << ch << std::endl;
	std::cout << "Після виклика: " << x << '\t' << ch1 << '\t' << question << std::endl << std::endl;


	std::cout << std::endl;
	std::cout << "До виклика: " << x << '\t' << ch1 << '\t' << question << std::endl;
	f3(&x, &ch1, &question);
	std::cout << "Не повертає значення" << std::endl;
	std::cout << "Після виклика: " << x << '\t' << ch1 << '\t' << question << std::endl << std::endl;

	///////////////////////////////////////

	std::cout << std::endl;
	std::cout << "До виклика: " << x << '\t' << ch1 << '\t' << question << std::endl;
	int *m = f4(x, ch1, question);
	std::cout << "Функція 1 повертає значення int: " << n << std::endl;
	std::cout << "Після виклика: " << x << '\t' << ch1 << '\t' << question << std::endl << std::endl;


	std::cout << std::endl;
	std::cout << "До виклика: " << x << '\t' << ch1 << '\t' << question << std::endl;
	char *p = f5(x, ch1, question);
	std::cout << "Функція 5 повертає значення int: " << n << std::endl;
	std::cout << "Після виклика: " << x << '\t' << ch1 << '\t' << question << std::endl << std::endl;

	///////////////////////////////////////

	int arr[] = { 1, 2, 3 };
	
	std::cout << "До виклика: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;	
	f6(arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << "Після виклика: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << "До виклика: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
	f7(*arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << "Після виклика: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << "До виклика: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
	f8(arr, sizeof(arr) / sizeof(arr[0]));
	std::cout << "Після виклика: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;

	///////////////////////////////////////

	struct_type arg;
	arg = { 100, 20, 'g' };
	//struct arg *p = &arg;

	std::cout << std::endl;
	std::cout << "Всі значення структури до виклика структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
	f9(arg);
	std::cout << "Всі значення структури після виклика структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Всі значення структури до виклика структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
	f10(&arg);
	std::cout << "Всі значення структури після виклика структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "Всі значення структури до виклика структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
	f11(arg);
	std::cout << "Всі значення структури після виклика структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
	std::cout << std::endl;

	system("pause");
	return 0;
}