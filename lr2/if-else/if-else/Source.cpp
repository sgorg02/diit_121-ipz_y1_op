/*
??????????? ??????? ????? ?? ??? ??????? ???????? ?????? ???????? ?? ?????? ???????.
*/


#include<iostream>
#include<Windows.h>
using namespace std;


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, p, q, r, s;

	int S, s1, s2;//S(???????), s1(???.1), s2(???.2)

	cout << "??????? ??????? ??????? a: ";
	cin >> a;

	cout << "??????? ??????? ??????? b: ";
	cin >> b;


	cout << "??????? ??????? ??????? ??????? p: ";
	cin >> p;

	cout << "??????? ??????? ??????? ??????? q: ";
	cin >> q;

	if ((p <= a) && (p <= b) && (q <= a) && (q <= b))
	{
		cout << "??????? ??????? ??????? ??????? r: ";
		cin >> r;

		cout << "??????? ??????? ??????? ??????? s: ";
		cin >> s;


		if ((r <= a) && (r <= b) && (s <= a) && (s <= b))
		{
			if ((q + p <= a) && (q + p <= b) && (p + r <= a) && (p + r <= b))//???????? ???????? ?? ??????????? ??? ?????
			{
				S = a * b;
				s1 = p * q;
				s2 = r * s;
				if (S - s1 - s2 >= 0)//????????? ?? ??????????? ???????? ?? ???????
				{
					cout << "????? ????????? ??????? ?? ??? ??????? " << endl;
				}
				else
				{
					cout << "?? ????? ????????? ??????? ?? ??? ??????? " << endl;
				}
			}
			else
			{
				cout << "??????? ?? ?????? ???????????? ???? ? ????? " << endl;
			}
		}

		else
		{
			cout << "??????? ??????? ???????2 ????????? ??????? ??????? ???????  " << endl;
		}
	}
	else
	{
		cout << "??????? ??????? ???????1 ????????? ??????? ??????? ???????  " << endl;
	}



	system("pause");
	return;
}
