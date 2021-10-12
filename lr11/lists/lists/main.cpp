#include <iostream>
#include <random>
#include <Windows.h>
typedef int DataType;
struct Node {
	DataType data;
	Node *prev;
	Node *next;
};

Node *newNode(DataType &value) {//��������� ������ ������ � ������
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

void Unknown_::addToHead(DataType value) {//��������� �������� � ������
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
void Unknown_::addToTail(DataType value) {//��������� �������� � ������
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
void Unknown_::Filling() {//��������� ��������� �� ��������� ���������� �����
	int Lb, Rb, quantity;
	std::cout << "������ ������� �������� �� ����� ��������: ";
	std::cin >> quantity;
	std::cout << "������ ��� �������: ";
	std::cin >> Lb;
	std::cout << "������ ��� �������: ";
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
void Unknown_::delFromHead() {//��������� �������� � ������
	if (head) {
		if (head == tail) {
			std::cout << "��������� �������: " << head->data << std::endl;
			delete head;
			head = tail = NULL;
		}
		else {
			Node *tmp = head->next;
			std::cout << "��������� �������: " << head->data << std::endl;
			delete head;
			head = tmp;
			head->prev = NULL;
		}
		Count--;
	}
}
void Unknown_::delFromTail() {//��������� �������� � ������
	if (head) {
		if (head == tail) {
			std::cout << "��������� �������: " << head->data << std::endl;
			delete head;
			head = tail = NULL;
		}
		else {
			Node *tmp = tail->prev;
			std::cout << "��������� �������: " << tail->data << std::endl;
			delete tail;
			tail = tmp;
			tail->next = NULL;
		}
		Count--;
	}
}
void Unknown_::printFromTail() {//���� ������������ ������� ����� ��������� � ������
	Node *tmp = tail;
	while (tmp) {
		std::cout << tmp->data << ' ';
		tmp = tmp->prev;
	}
	std::cout << std::endl;
}
void Unknown_::printFromHead() {//���� ������������ ������� ����� ��������� � ������
	Node *tmp = head;
	while (tmp) {
		std::cout << tmp->data << ' ';
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void Unknown_::rightNeighbor(DataType value) {//����������� ������� ����� �������� ��������
	DataType a;
	Node *tmp = head;
	while (tmp) {
		if (value == tmp->data) {
			if (tmp->next != NULL)
				std::cout << "� ����� ������� = " << value << ", ������ ���� = " << tmp->next->data << std::endl;
			else
				std::cout << "� ����� ������� = " << value << ", ��� �� ������ ���� � ���� ���� ������� �����!" << std::endl;
		}
	tmp = tmp->next;
	}
}

void Unknown_::excludeItems() {//ǳ ������ ��������� � ��������, �� ����� �� ���� ���� �����
	DataType current_item, right_neighbor, left_neighbor;
	int pos = 1;
	Node *tmp = head;
	while (tmp) {
		current_item = tmp->data;
		if (pos != Count && pos != 1) {
			left_neighbor = tmp->prev->data;//���� ����
			right_neighbor = tmp->next->data;//������ ����
			//std::cout << "������� = " << current_item << ", ������ ���� = " << right_neighbor << ", ���� ���� = " << left_neighbor << std::endl;
			if (current_item < (right_neighbor + left_neighbor)) {
				std::cout << "��������� ������� = " << current_item << std::endl;
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
		}
		else
			std::cout << "� ����� ������� = " << current_item << ", ��� �� ������ ���� � ����� ���� ������� ��� ����� �����!" << std::endl;
		tmp = tmp->next;
		pos++;
	}
}
int input_value() {//�������� ��������
	int value;
	while (true) {
		system("cls");
		std::cout << "����� �������: ";
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
		std::cout << "1. ���� ������" << std::endl;
		std::cout << "2. ��������� ��������" << std::endl;
		std::cout << "3. ��������� ��������" << std::endl;
		std::cout << "4. ����� ������� ��������" << std::endl;
		std::cout << "5. ǳ ������ ��������� � ��������, �� ����� �� ���� ���� �����" << std::endl;
		std::cout << "6. �����" << std::endl;
		std::cin >> menu;

		switch (menu) {
		case 1: {
			do {
				system("cls");
				std::cout << "1.������� ������ � ������" << std::endl;
				std::cout << "2.������� ������ � ������" << std::endl;
				std::cout << "3.����� � ����" << std::endl;
				std::cout << "4.����� � ��������" << std::endl;
				std::cin >> paragraph;
				switch (paragraph) {
				case 1: {
					system("cls");
					std::cout << "���� ������ � ������: " << std::endl;
					unknown.printFromHead();
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					std::cout << "���� ������ � ������: " << std::endl;
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
				std::cout << "1.��������� �������� � ������" << std::endl;
				std::cout << "2.��������� �������� � ������" << std::endl;
				std::cout << "3.��������� �������� �� ��������� ���������� �����" << std::endl;
				std::cout << "4.����� � ����" << std::endl;
				std::cout << "5.����� � ��������" << std::endl;
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
				std::cout << "1.�������� �������� � ������" << std::endl;
				std::cout << "2.�������� �������� � ������" << std::endl;
				std::cout << "3.����� � ����" << std::endl;
				std::cout << "4.����� � ��������" << std::endl;
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
			std::cout << "������ �����: ";
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