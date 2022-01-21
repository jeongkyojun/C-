#include<iostream>
using namespace std;

int main()
{
	int num[100001];
	int top = 0;
	int tc,number;
	long long sum = 0;

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> number;
		if (number == 0)
		{
			
			sum -= num[--top];
		}
		else
		{
			sum += number;
			num[top++] = number;
		}
	}
	cout << sum << endl;
}