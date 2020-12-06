#include<iostream>

using namespace std;

/*
* Àç±Í¸¦ ÀÌ¿ëÇÑ ÆÑÅä¸®¾ó
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