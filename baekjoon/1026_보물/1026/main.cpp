#include<iostream>

using namespace std;

int main()
{
	/*
	* S = A[0]xB[0] + ... + A[n-1]xB[n-1]
	* S�� ���� ���� �۰� ����� ���� A�� ��迭����.
	* 
	* 11160
	* 27831
	* 11016
	* =2+7+0+3+6 = 18
	* 
	* B�� ������ Ȯ�� �ݴ�� ��ġ�ϸ� �ȴ�.
	* 
	* N<=50 , A&B <=100
	*/
	int A[51],B[51],Asize[51],Bsize[51];
	int N, num;
	int res = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A[i] = num;
		Asize[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
			{
				Asize[j]++;
			}
			else
			{
				Asize[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		B[i] = num;
		Bsize[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (B[j] < B[i])
			{
				Bsize[j]++;
			}
			else
			{
				Bsize[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Bsize[j] == N - Asize[i] + 1)
			{
				cout << A[i] << " * " << B[j]<<"("<<Asize[i]<<"+"<<Bsize[j]<<")"<<endl;
				res += A[i] * B[j];
				break;
			}
		}
	}
	cout << res;
}