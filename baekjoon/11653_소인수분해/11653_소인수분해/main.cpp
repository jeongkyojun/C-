#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	for (int i = 2; i <= N; i++)
	{
		while (true)
		{
			if (N % i == 0)
			{
				cout << i << endl;
				N /= i;
			}
			else
				break;
		}
	}
}