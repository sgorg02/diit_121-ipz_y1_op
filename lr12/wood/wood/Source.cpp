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

void push(int RAM, std::string model, float diagonal, node **tree) { //��������� ���� ������� ������
	if ((*tree) == NULL) {//���� ������ �� ����
		(*tree) = new node;
		(*tree)->RAM = RAM;
		(*tree)->smartphone_model = model;
		(*tree)->diagonal = diagonal;
		(*tree)->left = (*tree)->right = NULL;//������� ���'��� ��� ���������� ���������
		return;
	}

	if (RAM < (*tree)->RAM)
		push(RAM, model, diagonal, &(*tree)->left);
	else
		push(RAM, model, diagonal, &(*tree)->right);
}
void treeprint(node **tree) {// ����������� ����� ������
	if ((*tree) != NULL) { //���� �� ���������� ������ ����
		treeprint(&(*tree)->left); //����������� ������� ��� ������ ���������
		treeprint(&(*tree)->right); //����������� ������� ��� ������� ���������
		std::cout << "��'�� ��� = " << (*tree)->RAM << std::endl;
		std::cout << "������ ��������� = " << (*tree)->smartphone_model << std::endl;
		std::cout << "ĳ������� =  " << (*tree)->diagonal << std::endl << std::endl;
	}
}
void freemem(node *tree) {//����� ��������� ������
	if (tree != NULL) {
		freemem(tree->left);
		freemem(tree->right);
		free(tree);
	}
}
void file(node **tree) { //������� ������ � �����
	int RAM;
	float diagonal;
	std::string model, namefile;
	std::cout << "������ ��'� �����: ";
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
		std::cout << "���� �� �������!" << std::endl;
	ifs.close();
}
void file_take(std::ostream& ifs, node **tree) {//������ �������� ������ ������ � ��������� ���� � ������ � ������ � �������, �� � ��� �����
	if ((*tree) != NULL) { //���� �� ���������� ������ ����
		file_take(ifs, &(*tree)->left); //����������� ������� ��� ������ ���������
		file_take(ifs, &(*tree)->right); //����������� ������� ��� ������� ���������
		ifs << (*tree)->RAM << ' ' << (*tree)->smartphone_model << ' ' << (*tree)->diagonal << '\n'; //�������� �������� � ����
	}
}
node *MaxValue(node *tree) {//���������� ������� � ������������ ������
	if (tree->right != NULL)
		return  MaxValue(tree->right);
	else
		return tree;
}
int input_check(int choice) {//�������� ������� ��� int
	int n;
	while (true) {
		switch (choice) {
		case 1:
			std::cout << "������� ���������� ���������: ";
			break;
		case 2:
			std::cout << "��'�� ��� = ";
			break;
		case 3:
			std::cout << "������� ���� ����� ��������: ";
			break;
		default:
			break;
		}
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "���������� ��������!" << std::endl;
		}
		else
			return n;
	}
}
float input_check_float() { //�������� ������� ��� float
	float n;
	while (true) {
		std::cout << "ĳ������� = ";
		std::cin >> n;
		if ((std::cin.peek() != '\n') || !(n > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "���������� ��������!" << std::endl;
		}
		else
			return n;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	node *tree = NULL;
	int n, menu; //n - ������� ��������, menu - ����� ����
	int RAM;
	float diagonal;
	std::string model;
	do {
		system("cls");
		std::cout << "1. ���� ������" << std::endl;
		std::cout << "2. ������ ������� �� ������" << std::endl;
		std::cout << "3. ��������� ������� � ������������ ������" << std::endl;
		std::cout << "4. ������� ������ � �����" << std::endl;
		std::cout << "5. �������� ������ � �����" << std::endl;
		std::cout << "6. �����" << std::endl;
		std::cin >> menu;

		switch (menu) {
		case 1: {
			system("cls");
			std::cout << "������" << std::endl;
			treeprint(&tree);
			std::cout << std::endl;
			system("pause");
			break;
		}
		case 2: {
			system("cls");
			n = input_check(1);

			for (int i = 0; i<n; ++i) {
				RAM = input_check(2); //���� �����(���)
				std::cin.ignore(32767, '\n');
				std::cout << "������ ��������� = ";
				std::getline(std::cin, model);
				diagonal = input_check_float(); //���� �����(��������)
				std::cout << std::endl;
				push(RAM, model, diagonal, &tree);
			}
			system("pause");
			break;
		}
		case 3: {
			system("cls");
			std::cout << "������������ ������� ������" << std::endl;;
			node* max = MaxValue(tree);
			std::cout << "��'�� ��� = " << max->RAM << std::endl;
			std::cout << "������ ��������� = " << max->smartphone_model << std::endl;
			std::cout << "ĳ������� = " << max->diagonal << std::endl;
			system("pause");
			break;
		}
		case 4: {
			system("cls");
			file(&tree); //������� ������ � �����
			system("pause");
			break;
		}
		case 5: {
			system("cls");
			std::string namefile;
			std::cout << "������ ��'� �����: ";
			std::cin >> namefile;
			std::ofstream ifs(namefile); //³������ �����
			if (ifs.is_open()) 
				file_take(ifs, &tree); //����� ������ � ����
			else
				std::cout << "���� �� �������!" << std::endl;
			ifs.close(); //�������� �����
			system("pause");
			break;
		}
		case 6:
			freemem(tree); //��������� ����� ������
			return 0;
		default:
			break;
		}
	} while(menu != 6);
}