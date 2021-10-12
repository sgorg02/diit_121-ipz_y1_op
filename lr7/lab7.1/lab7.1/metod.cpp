#include <iostream>
#include "metod.h"

int f1(int x, char ch, bool f)
{
	std::cout << "За значеню" << std::endl;
	x += x;
	ch = 'a';
	f = !f;
	return x;
}
int f2(int &x, char &ch, bool &f)
{
	std::cout << "За посиланням" << std::endl;
	x += x;
	ch = 'b';
	f = !f;
	return ch;
}
void f3(int *x, char *ch, bool *f)
{
	std::cout << "За вказівником" << std::endl;
	*x += *x;
	*ch = 'c';
	*f = !(*f);
}

int* f4(int x, char ch, bool f)
{
	std::cout << "За посиланням" << std::endl;
	x += x;
	ch = 'd';
	f = !f;
	return &x;
}
char* f5(int &x, char &ch, bool &f)
{
	std::cout << "За посиланням" << std::endl;
	x += x;
	ch = 'e';
	f = !f;
	return &ch;
}

void f6(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	std::cout << "Сума: " << sum << std::endl;
	std::cout << "Функція випадково перезаповняє масив, також рахує суму елементів. Не повертає значення" << std::endl;
}
void f7(int &arr, int size)
{
	int sum = 0;
	int *p = &arr;
	for (int i = 0; i < size; i++)
	{
		p[i] = rand() % 10;
	}

	for (int i = 0; i < size; i++)
	{
		sum += p[i];
	}

	std::cout << "Сума: " << sum << std::endl;
	std::cout << "Функція випадково перезаповняє масив, також рахує суму елементів. Не повертає значення" << std::endl;
}
void f8(int *arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	std::cout << "Сума: " << sum << std::endl;
	std::cout << "Функція випадково перезаповняє масив, також рахує суму елементів. Не повертає значення" << std::endl;
}

void f9(struct struct_type parm)
{
	parm.a = 200;
	parm.b = 40;
	parm.ch3 = 'f';
	std::cout << "Всі зпначення структури: " << parm.a << ", " << parm.b << ", " << parm.ch3 << std::endl;
}

void f10(struct_type *arg)
{
	arg->a = 200;
	arg->b = 40;
	arg->ch3 = 'f';
	std::cout << "Всі зпначення структури: " << arg->a << ", " << arg->b << ", " << arg->ch3 << std::endl;
}

void f11(struct_type &arg)
{
	arg.a = 200;
	arg.b = 40;
	arg.ch3 = 'f';
	std::cout << "Всі зпначення структури: " << arg.a << ", " << arg.b << ", " << arg.ch3 << std::endl;
}