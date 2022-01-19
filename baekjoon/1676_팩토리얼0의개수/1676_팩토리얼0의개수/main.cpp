#include<iostream>

using namespace std;

int main()
{
	int num,j;
	int res = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		j = i;
		while (j % 5 == 0)
		{
			res++;
			j /= 5;
		}
		
	}
	cout << res;
}