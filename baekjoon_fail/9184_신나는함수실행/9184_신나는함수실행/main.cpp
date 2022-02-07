#include<iostream>
#include<vector>
using namespace std;

long long int w(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;

	if (a > 20 or b > 20 or c > 20)
		return w(20, 20, 20);

	if (a < b && b < c)
		return	w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	vector<vector<vector<long long> > > cube;
	vector<vector<long long> > mat;
	vector<long long > vec;
	int x, y, z;
	for (int i = 0; i <= 20; i++)
	{
		vec.push_back(1);
	}
	for (int i = 0; i <= 20; i++)
	{
		mat.push_back(vec);
	}
	for (int i = 0; i <= 20; i++)
	{
		cube.push_back(mat);
	}

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int k = 0; k <= 20; k++)
			{

			}
		}
	}
}