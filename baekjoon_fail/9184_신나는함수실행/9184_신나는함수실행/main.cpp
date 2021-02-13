#include<iostream>
#include<vector>
using namespace std;

int w(int a, int b, int c)
{
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;

	if (a > 20 or b > 20 or c > 20)
		return w(20, 20, 20);

	if (a < b && b < c)
		return	w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
/*
* a<=0 || b<=0 || c<=0 이면 1
* a>20 || b>20 || c>20 이면 w(20,20,20)
* a<b<c 면 w(a,b,c) = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c)
* 그 외 
* w(a-1,b,c) + b(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
* 
* 0 0 0 = 1
* 1 0 0 = 1
* 0 1 0 = 1
* 0 0 1 = 1
* 1 1 1 = 1 + 1 + 1 - 1 = 2
* 1 1 2 = 1 + 1 + 1 - 1 = 2
* 1 2 3 = 1 2 2 + 1 1 2 + 1 1 3 = 2+2+2 = 6
* a = 1 인 모든 값  = 2 (123 제외)
* a = 2 인 모든 값  =  
*/
int main()
{
	vector<vector<vector<long long> > > cube;
	vector<vector<long long> > mat;
	vector<long long > vec;

	for (int i = 0; i <= 70; i++)
	{
		vec.push_back(1);
	}
	for (int i = 0; i <= 70; i++)
	{
		mat.push_back(vec);
	}
	for (int i = 0; i <= 70; i++)
	{
		cube.push_back(mat);
	}
	for (int i = 50; i <= 70; i++) // 0 = 50
	{
		for (int j = 50; j <= 70; j++)
		{
			for (int k = 50; k <= 70; k++)
			{
				if (i <= 50 || j <= 50 || k <= 50)
					cube[i][j][k] = 1;
				else if (i < j && j < k)
					cube[i][j][k] = cube[i][j][k-1]+cube[i][j - 1][k - 1] - cube[i][j - 1][k];
				else
				{
					cube[i][j][k] = cube[i - 1][j][k] + cube[i - 1][j - 1][k] + cube[i - 1][j][k - 1] - cube[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		//int result = w(a, b, c);
		cout << "w(" << a << "," << b << "," << c << ") = ";
		if (a <= 0 || b <= 0 || c <= 0)
		{
			cout << 1 << endl;
		}
		else if (a > 20 || b > 20 || c > 20)
		{
			cout << cube[70][70][70] << endl;
		}
		else
		{
			cout << cube[a + 50][b + 50][c + 50] << endl;
		}
		/*
		if (result != cube[a + 50][b + 50][c + 50])
		{
			cout << result << " != " << cube[a + 50][b + 50][c + 50];
			cout << " (" << a <<" "<< b <<" "<< c << ")" << endl;
		}
		*/
	}
}