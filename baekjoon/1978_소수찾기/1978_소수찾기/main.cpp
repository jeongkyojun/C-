#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	int num;
	int result;
	cin >> N;
	result = N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 1)
		{
			result--;
		}
		else
		{
			for (int j = 2; j < num; j++)
			{
				if (num % j == 0)
				{
					result--;
					break;
				}
			}
		}
	}
	cout << result << endl;
}