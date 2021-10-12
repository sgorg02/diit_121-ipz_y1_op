/*9. Для кожного рядка текстового файлу сформувати новий рядок із слів-паліндромів. 
Підрахувати кількість слів в новому рядку. Результати обробки кожного рядка записати у файл у вигляді значення лічильника слів і нового рядка. 
Вимоги до програми:
	для обробки файлів використати рядки в стилі С;
	максимально задіяти функції стандартної бібліотеки (забороняється дублювати дії функцій стандартної бібліотеки власними функціями);
	імена файлів ввести з клавіатури;
	передбачити перевірку всіх операцій роботи з файлами (відкриття, читання, запису);
	управління виконанням програми здійснити на основі текстового меню користувача;
	передбачити обробку необмеженої кількості файлів;
	результати роботи програми вивести у файл та продублювати на екрані.
Вимоги до тексту програми:
	специфікації програми і її функцій;
	коментарі щодо призначення блоків програми, дій окремих операторів для по-яснення алгоритму;
	самодокументованість коду: всі ідентифікатори повинні мати назви, що відповідають суті змінних.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Windows.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int counter = 0;
	FILE *S1, *S2;
	errno_t err, err1;
	char name[20];
	char text[256];
	char redone_text[256];

	std::cout << "Введіть імя другого файлу: ";
	std::cin.getline(name, 20);

	err = fopen_s(&S1, "S1.txt", "r");
	err1 = fopen_s(&S2, name, "w+");

	if ((err == 0) && (err1 == 0)) {

		int ix = 0, i = 1;
		char character;
		while (fgets(text, 256, S1) != NULL) {
			std::cout << "Текст" << i << " = " << text << std::endl;
			ix = 0;
			while (text[ix]) {// пока не конец строки
				character = text[ix];
				if ((character != ' ') || (character != ',') || (character != '.') || (character != '\t') || (character != '\0')) {
					if (islower(character)) // если текущий символ строчная буква
						character = toupper(character);// преобразовать символ в заглавную букву
					else 
						character = tolower(character);
					redone_text[ix] = character;
					counter++;
				}
				ix++;
			}
			redone_text[ix] = '\0';
			std::cout << "Счетчик " << counter << std::endl;
			std::cout << "Текст після перетворень = ";
			for(int j = 0; j < strlen(redone_text); j++)
				std::cout << redone_text[j];
			std::cout << std::endl;
			fprintf(S2, "%d", counter);
			fputc(' ', S2);
			fputs(redone_text, S2);
			i++;	
			memset(&redone_text[0], 0, strlen(redone_text));
		}
	}
	else
		std::cout << "Файли не відкрилися!" << std::endl;
	system("pause");
	return 0;
}