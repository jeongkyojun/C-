#include<iostream>

using namespace std;

/*
* A �� N�� ��� -> N % A == 0, A!=0, A!=N
* 
*/

int main()
{
	int num,n,a=1000001,b=1;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> n;
		if (n < a)
			a = n;
		if (n > b)
			b = n;
	}
	cout << a * b;
}