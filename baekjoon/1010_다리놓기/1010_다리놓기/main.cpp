#include<iostream>

using namespace std;

int main()
{
	int mat[31][31];
	int N, M,T;
	cin >> T;
	/* 
	* ���⼭ i�� n , j�� r �� �ȴ�.
	* Comb(n,r) = Comb(n-1, r-1) + Comb(n-1,r) �̹Ƿ�
	* DP�� �̿��� Ǯ����.
	* 
	* Comb(n,r) = n! / (r! * (n-r)!)
	*/
	for (int i = 1; i < 31; i++)
	{
		mat[i][1] = i;
		mat[i][i] = 1;
	}
	for (int test = 0; test < T; test++)
	{
		cin >> N >> M;
		for (int j = 2; j <= M; j++)
		{
			for (int i = 2; i < j; i++)
			{
				mat[j][i] = mat[j - 1][i - 1] + mat[j - 1][i];
			}
		}
	
		cout << mat[M][N] << endl;
	}
}