/*
�������� ��������� �� ��������� ����� ������ v �� u
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

	cout << "������ n = ";
	while (!(cin >> n) || (cin.peek() != '\n')) // ���� ��� �������� ������� ���� �� �������
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "������� �����! ��������� ����. n ������ ���� �����" << endl;
		cout << "������ n = ";
	}


	while ((n < 3) || (cin.peek() != '\n')) // ���� ��� �������� ������� �� ������� ����� 
	{
		cin.clear();
		while (cin.get() != '\n');
		cerr << "! ����� n ������ ���� ����� 2" << endl;
		cout << "������ n = ";
		cin >> n;
	}


		int i = 3;
		do
		{
			u_result = u2 - (u1 * v2) - v1;
			V_result = u2 - v2;
			cout << "³������ V" << i << " = " << V_result << endl; // ��� ���� ��� ��������� ��������� ������� ����
			//cout << "³������ u" << i << " = " << u_result << endl;
			u1 = u2;
			v1 = v2;
			u2 = u_result;
			v2 = V_result;
			--n;
		} while (i <= n);

		/*cout << " ³������ V = " << V_result << endl;  // ��� ���� ������� ��� ��������� ���������� ��������
		cout << " ³������ u = " << u_result << endl;*/
	


	system("pause");
	return;
}