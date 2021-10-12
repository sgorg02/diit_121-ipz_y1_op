#include <iostream>
#include <random>
#include <Windows.h>
typedef int DataType;
struct Node {
	DataType data;
	Node *prev;
	Node *next;
};

Node *newNode(DataType &value) {//додавання нового вузола в список
	Node *tmp = new Node;
	tmp->data = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}

struct Unknown_ {
	int Count = NULL;
	Node* head = NULL;
	Node* tail = NULL;
	bool isEmpty();
	void addToHead(DataType value);
	void addToTail(DataType value);
	void Filling();
	void delFromHead();
	void delFromTail();
	void printFromHead();
	void printFromTail();
	void rightNeighbor(DataType value);
	void excludeItems();
};
bool Unknown_::isEmpty() {
	return (head == NULL) ? true : false;
}

void Unknown_::addToHead(DataType value) {//додавання елемента з голови
	Node *tmp = newNode(value);
	if (head) {
		head->prev = tmp;
		tmp->next = head;
	}
	else
		tail = tmp;
	head = tmp;
	Count++;
}
void Unknown_::addToTail(DataType value) {//додавання елемента з хвоста
	Node *tmp = newNode(value);
	if (tail) {
		tail->next = tmp;
		tmp->prev = tail;
	}
	else
		head = tmp;
	tail = tmp;
	Count++;
}
void Unknown_::Filling() {//створення структури за допомогою генератора чисел
	int Lb, Rb, quantity;
	std::cout << "Введіть кількість елементів які треба добавити: ";
	std::cin >> quantity;
	std::cout << "Введіть ліву границю: ";
	std::cin >> Lb;
	std::cout << "Введіть ліву границю: ";
	std::cin >> Rb;
	DataType value;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<DataType> dis(Lb, Rb);
	for (int i = 0; i < quantity; i++) {
		value = dis(gen);
		Node *tmp = newNode(value);
		if (head) {
			head->prev = tmp;
			tmp->next = head;
		}
		else
			tail = tmp;
		head = tmp;
		Count++;
	}
			
}
void Unknown_::delFromHead() {//видалення елемента з голови
	if (head) {
		if (head == tail) {
			std::cout << "Видаляємо елемент: " << head->data << std::endl;
			delete head;
			head = tail = NULL;
		}
		else {
			Node *tmp = head->next;
			std::cout << "Видаляємо елемент: " << head->data << std::endl;
			delete head;
			head = tmp;
			head->prev = NULL;
		}
		Count--;
	}
}
void Unknown_::delFromTail() {//видалення елемента з хвоста
	if (head) {
		if (head == tail) {
			std::cout << "Видаляємо елемент: " << head->data << std::endl;
			delete head;
			head = tail = NULL;
		}
		else {
			Node *tmp = tail->prev;
			std::cout << "Видаляємо елемент: " << tail->data << std::endl;
			delete tail;
			tail = tmp;
			tail->next = NULL;
		}
		Count--;
	}
}
void Unknown_::printFromTail() {//друк інформаційної частини вузла структури з голови
	Node *tmp = tail;
	while (tmp) {
		std::cout << tmp->data << ' ';
		tmp = tmp->prev;
	}
	std::cout << std::endl;
}
void Unknown_::printFromHead() {//друк інформаційної частини вузла структури з хвоста
	Node *tmp = head;
	while (tmp) {
		std::cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void Unknown_::rightNeighbor(DataType value) {//знаходження правого сусіда заданого елемента
	DataType a;
	Node *tmp = head;
	while (tmp) {
		if (value == tmp->data) {
			if (tmp->next != NULL)
				std::cout << "Є такий елемент = " << value << ", правий сусід = " << tmp->next->data << std::endl;
			else
				std::cout << "Є такий елемент = " << value << ", але він останій тому в ного нема правого сусіда!" << std::endl;
		}
	tmp = tmp->next;
	}
}

void Unknown_::excludeItems() {//Зі списку виключити ті елементи, які менші за суму своїх сусідів
	DataType current_item, right_neighbor, left_neighbor;
	int pos = 1;
	Node *tmp = head;
	while (tmp) {
		current_item = tmp->data;
		if (pos != Count && pos != 1) {
			left_neighbor = tmp->prev->data;//лівий сусід
			right_neighbor = tmp->next->data;//правий сусід
			//std::cout << "Елемент = " << current_item << ", правий сусід = " << right_neighbor << ", лівий сусід = " << left_neighbor << std::endl;
			if (current_item < (right_neighbor + left_neighbor)) {
				std::cout << "Виключаємо елемент = " << current_item << std::endl;
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
		}
		else
			std::cout << "Є такий елемент = " << current_item << ", але він останій тому в нього нема правого або лівого сусіда!" << std::endl;
		tmp = tmp->next;
		pos++;
	}
}
int input_value() {//перевірка елемента
	int value;
	while (true) {
		system("cls");
		std::cout << "Ведіть елемент: ";
		std::cin >> value;
		if ((std::cin.peek() != '\n')) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
			return value;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Unknown_ unknown;
	int menu, paragraph;
	int value;

	do {
		system("cls");
		std::cout << "1. Вивід списку" << std::endl;
		std::cout << "2. Додавання елемента" << std::endl;
		std::cout << "3. Видалення елемента" << std::endl;
		std::cout << "4. Пошук правого елемента" << std::endl;
		std::cout << "5. Зі списку виключити ті елементи, які менші за суму своїх сусідів" << std::endl;
		std::cout << "6. Вихід" << std::endl;
		std::cin >> menu;

		switch (menu) {
		case 1: {
			do {
				system("cls");
				std::cout << "1.Вивести список з голови" << std::endl;
				std::cout << "2.Вивести список з хвоста" << std::endl;
				std::cout << "3.Вихід в меню" << std::endl;
				std::cout << "4.Вихід з програми" << std::endl;
				std::cin >> paragraph;
				switch (paragraph) {
				case 1: {
					system("cls");
					std::cout << "Вивід списку з голови: " << std::endl;
					unknown.printFromHead();
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					std::cout << "Вивід списку з хвоста: " << std::endl;
					unknown.printFromTail();
					system("pause");
					break;
				}
				case 4:
					return 0;
				default:
					break;
				}
			} while (paragraph != 3);
			break;
		}
		case 2: {
			do {
				system("cls");
				std::cout << "1.Додавання елемента з голови" << std::endl;
				std::cout << "2.Додавання елемента з хвоста" << std::endl;
				std::cout << "3.Додавання елемента за допомогою генератора чисел" << std::endl;
				std::cout << "4.Вихід в меню" << std::endl;
				std::cout << "5.Вихід з програми" << std::endl;
				std::cin >> paragraph;
				switch (paragraph) {
				case 1: {
					system("cls");
					value = input_value();
					unknown.addToHead(value);
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					value = input_value();
					unknown.addToTail(value);
					system("pause");
					break;
				}
				case 3: {
					system("cls");
					unknown.Filling();
					system("pause");
					break;
				}
				case 5:
					return 0;
				default:
					break;
				}
			} while (paragraph != 4);
			break;
		}
		case 3: {
			do {
				system("cls");
				std::cout << "1.Виділення елемента з голови" << std::endl;
				std::cout << "2.Виділення елемента з хвоста" << std::endl;
				std::cout << "3.Вихід в меню" << std::endl;
				std::cout << "4.Вихід з програми" << std::endl;
				std::cin >> paragraph;
				switch (paragraph) {
				case 1: {
					system("cls");
					unknown.delFromHead();
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					unknown.delFromTail();
					system("pause");
					break;
				}
				case 4:
					return 0;
				default:
					break;
				}
			} while (paragraph != 3);
			break;
		}
		case 4: {
			system("cls");
			std::cout << "Введіть число: ";
			std::cin >> value;
			unknown.rightNeighbor(value);
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			unknown.excludeItems();
			system("pause");
			break;
		}
		case 6: 
			return 0;
		default:
			break;
		}
	} while (menu != 6);
}