#include<iostream>
#include<vector>

using namespace std;

void NQueen(vector<vector<int> > mat, int layer, int queen,int max ,int& res)
{
	int j = 1;
	for (int i = layer+1; i < max; i++,j++)
	{
		if (queen + j < max)
			mat[i][queen + j] = 0;
		if (queen - j >= 0)
			mat[i][queen - j] = 0;
		mat[i][queen] = 0;
	}
	mat[layer][queen] = 2;
	/*
	cout << "layer : " << layer << endl;
	for (int i = 0; i< mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	*/
	if (layer == max-2)
	{
		//cout << "find res" << endl<<endl;
		for (int i = 0; i < mat.size(); i++)
		{
			if (mat[max - 1][i]==1)
				res++;
		}
	}
	else
	{
		for (int i = 0; i < max; i++)
		{
			if (mat[layer + 1][i])
			{
				NQueen(mat, layer + 1, i, max, res);
			}
		}
	}
}

int main()
{
	vector<vector<int> >mat;
	int N,res = 0;
	cin >> N;
	if (N == 1)
		res = 1;
	else
	{
		vector<int> vec(N);
		for (int i = 0; i < N; i++)
			vec[i] = 1;
		for (int i = 0; i < N; i++)
			mat.push_back(vec);

		for (int i = 0; i <= (N - 2) / 2; i++)
		{
			cout << "layer " << i + 1 << endl;
			NQueen(mat, 0, i, N, res);
		}
		cout << "res : " << res << endl;
		res *= 2;
		if (N % 2 == 1)
			NQueen(mat, 0, N / 2, N, res);
	}
	cout << res << endl;
}