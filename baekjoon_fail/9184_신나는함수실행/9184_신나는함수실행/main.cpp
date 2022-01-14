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
	for (int i = 0; i <= 100; i++)
	{
		vec.push_back(1);
	}
	for (int i = 0; i <= 100; i++)
	{
		mat.push_back(vec);
	}
	for (int i = 0; i <= 100; i++)
	{
		cube.push_back(mat);
	}

	for (int a = 0; a <= 70; a++)
	{
		for (int b = 0; b <= 70; b++)
		{
			for (int c = 0; c <= 70; c++)
			{
				if (a <= 50 || b <= 50 || c <= 50)
				{
					cube[a][b][c] = 1;
				}
				else if (a < b && b < c)
				{
					cube[a][b][c] = cube[a][b][c - 1] + cube[a][b - 1][c] - cube[a][b - 1][c];
				}
				else
				{
					cube[a][b][c] = cube[a - 1][b][c] + cube[a - 1][b - 1][c] + cube[a - 1][b][c - 1] - cube[a - 1][b - 1][c - 1];
				}
			}
		}
	}
	/*
	while (true)
	{
		cin >> x >> y >> z;

		if (x == -1 && y == -1 && z == -1)
			break;
		if (x > 20 || y > 20 || z > 20)
		{
			x = 20;
			y = 20;
			z = 20;
		}
		cout << "w("<<x<<", "<<y<<", "<<z<<") = "<<cube[x + 50][y + 50][z + 50] << endl;

	}
	*/

	for (x = -50; x <=20; x++)
	{
		cout <<"x : " <<x << endl;
		for (y = -50; y <=20; y++)
		{
			for (z = -50; z <=20; z++)
			{
				if (x == -1 && y == -1 && z == -1)
					break;
				if (x > 20 || y > 20 || z > 20)
				{
					x = 20;
					y = 20;
					z = 20;
				}
				long long int res = w(x, y, z);
				if (res != cube[x + 50][y + 50][z + 50])
				{
					cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;
					cout << "------------------------------------------------" << endl;
					cout << res << " & " << cube[x + 50][y + 50][z + 50] << endl;
					return -1;
				}
			}
		}
	}
}