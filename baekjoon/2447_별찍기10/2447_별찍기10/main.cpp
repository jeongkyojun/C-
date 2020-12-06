#include<iostream>

using namespace std;

/*
* 재귀로 별 찍기
* 크기 N = N X N 정사각형 모양 
* 3이상인 경우 가운데를 제외
* ex)	***
*		* *
*		***
* 
* 3보다 클 경우 (N/3) x (N/3) 정사각형을 N/3의 패턴으로 둘러싼 형태
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