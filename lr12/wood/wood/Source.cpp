#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

struct node {
	int RAM;
	float diagonal;
	std::string smartphone_model;
	node *left;
	node *right;
};

void push(int RAM, std::string model, float diagonal, node **tree) { //Створення нової вершини дерева
	if ((*tree) == NULL) {//Якщо дерева не існує
		(*tree) = new node;
		(*tree)->RAM = RAM;
		(*tree)->smartphone_model = model;
		(*tree)->diagonal = diagonal;
		(*tree)->left = (*tree)->right = NULL;//Очищаємо пам'ять для наступного зростання
		return;
	}

	if (RAM < (*tree)->RAM)
		push(RAM, model, diagonal, &(*tree)->left);
	else
		push(RAM, model, diagonal, &(*tree)->right);
}
void treeprint(node **tree) {// постфіксний обхід дерева
	if ((*tree) != NULL) { //Пока не встретится пустой узел
		treeprint(&(*tree)->left); //Рекурсивная функция для левого поддерева
		treeprint(&(*tree)->right); //Рекурсивная функция для правого поддерева
		std::cout << "Об'єм ОЗУ = " << (*tree)->RAM << std::endl;
		std::cout << "Модель смартфону = " << (*tree)->smartphone_model << std::endl;
		std::cout << "Діагональ =  " << (*tree)->diagonal << std::endl << std::endl;
	}
}
void freemem(node *tree) {//Повне видалення дерева
	if (tree != NULL) {
		freemem(tree->left);
		freemem(tree->right);
		free(tree);
	}
}
void file(node **tree) { //Зчитуємо дерево з файла
	int RAM;
	float diagonal;
	std::string model, namefile;
	std::cout << "Введіть ім'я файла: ";
	std::cin >> namefile;
	std::ifstream ifs(namefile);
	if (ifs.is_open()) {
		ifs >> RAM;
		ifs >> model;
		ifs >> diagonal;
		push(RAM, model, diagonal, &(*tree));
		while (!ifs.eof()) {
			ifs >> RAM;
			ifs >> model;
			ifs >> diagonal;
			push(RAM, model, diagonal, &(*tree));
		}
	}
	else
		std::cout << "Файл не знайден!" << std::endl;
	ifs.close();
}
void file_take(std::ostream& ifs, node **tree) {//Запису бінарного дерева пошуку в текстовий файл в такому ж форматі і порядку, як і для друку
	if ((*tree) != NULL) { //Пока не встретится пустой узел
		file_take(ifs, &(*tree)->left); //Рекурсивная функция для левого поддерева
		file_take(ifs, &(*tree)->right); //Рекурсивная функция для правого поддерева
		ifs << (*tree)->RAM << ' ' << (*tree)->smartphone_model << ' ' << (*tree)->diagonal << '\n'; //Записуємо значення в файл
	}
}
node *MaxValue(node *tree) {//Визначення вершини з максимальним ключем
	if (tree->right != NULL)
		return  MaxValue(tree->right);
	else
		return tree;
}
int input_check(int choice) {//Перевірка значань тіпу int
	int n;
	while (true) {
		switch (choice) {
		case 1:
			std::cout << "Введите количество элементов: ";
			break;
		case 2:
			std::cout << "Об'єм ОЗУ = ";
			break;
		case 3:
			std::cout << "Елемент який треба видалити: ";
			break;
		default:
			break;
		}
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Некоректне введення!" << std::endl;
		}
		else
			return n;
	}
}
float input_check_float() { //Перевірка значань тіпу float
	float n;
	while (true) {
		std::cout << "Діагональ = ";
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Некоректне введення!" << std::endl;
		}
		else
			return n;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node *tree = NULL;
	int n, menu; //n - кількість елементів, menu - номер меню
	int RAM;
	float diagonal;
	std::string model;
	do {
		system("cls");
		std::cout << "1. Друк дерева" << std::endl;
		std::cout << "2. Додати вершину до дерева" << std::endl;
		std::cout << "3. Визначити вершину з максимальним ключем" << std::endl;
		std::cout << "4. Зчитати дерево з файла" << std::endl;
		std::cout << "5. Записати дерево в файла" << std::endl;
		std::cout << "6. Вихід" << std::endl;
		std::cin >> menu;

		switch (menu) {
		case 1: {
			system("cls");
			std::cout << "Дерево" << std::endl;
			treeprint(&tree);
			std::cout << std::endl;
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			n = input_check(1);

			for (int i = 0; i<n; ++i) {
				RAM = input_check(2); //Ввод ключа(ОЗУ)
				std::cin.ignore(32767, '\n');
				std::cout << "Модель смартфону = ";
				std::getline(std::cin, model);
				diagonal = input_check_float(); //Ввод даних(діагональ)
				std::cout << std::endl;
				push(RAM, model, diagonal, &tree);
			}
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			std::cout << "Максимальный элемент дерева" << std::endl;;
			node* max = MaxValue(tree);
			std::cout << "Об'єм ОЗУ = " << max->RAM << std::endl;
			std::cout << "Модель смартфону = " << max->smartphone_model << std::endl;
			std::cout << "Діагональ = " << max->diagonal << std::endl;
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			file(&tree); //Зчитуємо дерево з файла
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			std::string namefile;
			std::cout << "Введіть ім'я файла: ";
			std::cin >> namefile;
			std::ofstream ifs(namefile); //Відкритя файлу
			if (ifs.is_open()) 
				file_take(ifs, &tree); //Запис дерева в файл
			else
				std::cout << "Файл не знайден!" << std::endl;
			ifs.close(); //Закриття файлу
			system("pause");
			break;
		}
		case 6:
			freemem(tree); //Видалення всего дерева
			return 0;
		default:
			break;
		}
	} while(menu != 6);
}