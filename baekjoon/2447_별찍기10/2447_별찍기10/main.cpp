#include<iostream>

using namespace std;

/*
* ��ͷ� �� ���
* ũ�� N = N X N ���簢�� ��� 
* 3�̻��� ��� ����� ����
* ex)	***
*		* *
*		***
* 
* 3���� Ŭ ��� (N/3) x (N/3) ���簢���� N/3�� �������� �ѷ��� ����
*/

void dottingMat(int n,int row)
{
	if (n == 1||n==0)
		cout << "*";
	else if (n == 2)
		for (int i = 0; i < n; i++)
		{
				cout << "*";
		}
	else
	{
		if (row <= n/3)
		{
			for (int i = 0; i < 3; i++)
				dottingMat(n / 3, row%(n/3));
		}
		else if (row <= (n / 3) * 2)
		{
			dottingMat(n / 3, row % (n / 3));
			for (int i = 0; i < n / 3; i++)
			{
				cout << " ";
			}
			dottingMat(n / 3, row % (n / 3));
		}
		else
		{
			for (int i = 0; i < 3; i++)
				dottingMat(n / 3, row % (n / 3));
		}
	}
}

void dotting(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dottingMat(n, i);
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	dotting(n);
}