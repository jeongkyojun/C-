#include<iostream>

using namespace std;

/*
* ��͸� �̿��� ���丮��
*/

int pactorial(int n)
{
	if (n == 1||n==0)
		return 1;
	else
		return pactorial(n - 1) * n;
}

int main()
{
	int n;
	cin >> n;
	cout << pactorial(n);
}