#include<iostream>

using namespace std;
int main()
{
	int num;
	int sum=0;
	int min = 101;
	for (int i = 0; i < 7; i++)
	{
		cin >> num;
		if (num % 2 == 1)
		{
			sum += num;
			if (min > num)
				min = num;
		}
	}
	if (sum>0)
	{
		cout << sum << endl;
		cout << min << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}