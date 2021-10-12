/*Вимоги до програми: 
-дані для обробки вводяться з консолі;
-валідація вхідних даних;
-результати роботи програми виводяться на консоль;
-обчислення функції рекурсивним методом;
-обчислення функції ітераційним методом;
-обчислення функції за допомогою функцій математичної бібліотеки, якщо цеможливо.*/
#include <iostream>
#include <cmath>
#include "Windows.h"

double Recursion(int n, double x, double pow, int i = 3) { //звичайна рекурсія
	if (n == 1)
		return x;
	else
		return pow * x * x / static_cast<double>(i) + Recursion(n - 1, x, pow * x * x, i + 2);
}

double TailRecursion(int n, double x, double pow, int i = 3, double result = 0) { //хвостова рекурсія
	if (n == 1)
		return result + x;
	else 
		return TailRecursion(n - 1, x, pow * x * x, i + 2, result + pow * x * x / static_cast<double>(i));
}

double IterationMethod(int n, double x, double result = 0) { //ітераційний метод обчислення
	double pow = x;
	for (int i = 3; n != 1; n--) {
		result += pow * x * x / static_cast<double>(i);
		pow = pow * x * x;
		i += 2;
	}
	return result + x;
}

int Input_n() {
	system("cls");
	int n;
	while (true) {
		std::cout << "Введіть n: ";
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "На жаль, цей введення неправильне. Число n повино бути більше за 0. Повторіть знову." << std::endl;
		}
		else
			return n;
	}
}

double Input_x() {
	double x;
	system("cls");
	while (true) {
		std::cout << "Введіть x: ";
		std::cin >> x;
		if ((std::cin.peek() != '\n') || !(x < 1) || !(x > -1)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "На жаль, цей введення неправильне. Число n повино вадповідати діапозано (-1<x<1). Повторіть знову." << std::endl;
		}
		else
			return x;
	}
}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	double x;
	n = Input_n();
	x = Input_x();
	system("cls");
	std::cout << "Число n = " << n << std::endl;
	std::cout << "Число x = " << x << std::endl;
	std::cout << "Рекурсивний метод обчислення(звичайна): " << 2 * Recursion(n, x, x) << std::endl; // вызов рекурсивной функции
	std::cout << "Рекурсивний метод обчислення(хвостова): " << 2 * TailRecursion(n, x, x) << std::endl; // вызов рекурсивной функции
	std::cout << "Обчислення функції за допомогою функцій математичної бібліотеки: " << log((1 + x)/(1 - x)) << std::endl;
	std::cout << "Ітераційний метод обчислення: " << 2 * IterationMethod(n, x) << std::endl;
	system("pause");
	return 0;
}
