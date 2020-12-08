#include<iostream>
#include<cmath>
using namespace std;

int boundary(int n)
{
	//3 -> 1
	//4 -> 2
	if (n == 3)
		return 1;
	if (n == 4)
		return 19;
	return 9*boundary(n-1)+9*boundary(n-2)+boundary_6(n);
	// 5ÀÏ °æ¿ì = 100 + 9*19 + 9*1
}
int boundary_6(int n)
{
	//3 -> 0
	//4 -> 1 (10)
	int b = n - 3;
	return pow(10, b);
}
int main()
{
	int n, head,tail;
	int res, num;
	cin >> n;
	int cut = 3;
	while (cut > 3)
	{
		for (int i = 0; i < 10; i++)
		{
			num = 9 - i;
			if ()
			{

			}
		}
	}
}