#include<iostream>
#include<vector>
using namespace std;

/*
* a층의 b호에 살려면 a-1층의 1호부터 b호까지의 사람 수 합만큼 사람이 있어야 한다.
* 입력:
* k, n 입력 -> k층의 n호에 사는 사람 수는?
* 
* 0층 : 1	2	3	4	5	6	.....	n
* 1층 : 1	3	6	10	15	21	.....	n(n-1)/2
* 2층 : 1	4	10	20	35	56	.....	n(n-1)(2n-1)/12-n(n-1)/4			
* -> (k,n) = (k,n-1) + (k-1,n)
*/

int main()
{
	vector<vector<int> > mat;
	vector<int> vec;
	int T, k, n;
	for(int i=0;i<14;i++)
	{
		vec.push_back(1);
	}
	for (int i = 0; i <= 14; i++)
	{
		mat.push_back(vec);
	}
	for (int i = 0; i < 14; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			if (i == 0)
			{
				mat[i][j] = j + 1;
			}
			else
			{
				mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
			}
		}
	}
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> k;
		cin >> n;	
		cout << mat[k][n-1] << endl;
	}
}