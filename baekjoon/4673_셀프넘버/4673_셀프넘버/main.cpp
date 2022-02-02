#include<iostream>

using namespace std;

int main()
{
	bool b[10001];
	for (int i = 0; i < 10001; i++)
		b[i] = true;
	for (int i = 1; i <= 10000;i++)
	{
		if (!b[i])
			continue;
		for (int j = i; j <= 10000;)
		{
			int x = j; // x = 1
			int s = 0;
			while (x > 0)
			{
				s += x % 10; // s = 1
				x /= 10;
			}
			if (j+s < 10001)
				b[j + s] = false; 
			j = j + s;
		}
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (b[i])
			cout << i << endl;
	}
}