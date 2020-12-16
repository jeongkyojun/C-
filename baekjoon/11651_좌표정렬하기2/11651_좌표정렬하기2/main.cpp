#include<iostream>
#include<vector>
using namespace std;

void Qsort(vector<vector<int> >& mat, int low, int high)
{
	int j = low, k = low;
	vector<int> tmp;
	if (low < high)
	{
		for (int i = low; i <= high; i++)
		{
			if (mat[i][1] < mat[k][1])
			{
				tmp = mat[i];
				mat[i] = mat[++j];
				mat[j] = tmp;
			}
			else if (mat[i][1] == mat[k][1])
			{
				if (mat[i][0] < mat[k][0])
				{
					tmp = mat[i];
					mat[i] = mat[++j];
					mat[j] = tmp;
				}
			}
		}
		tmp = mat[k];
		mat[k] = mat[j];
		mat[j] = tmp;
		Qsort(mat, low, j - 1);
		Qsort(mat, j + 1, high);
	}
}

int main()
{
	vector<vector<int> > mat;
	vector<int>vec(2);

	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		vec[0] = a;
		vec[1] = b;
		mat.push_back(vec);
	}
	Qsort(mat, 0, mat.size() - 1);
	for (int i = 0; i < mat.size(); i++)
	{
		printf("%d %d\n", mat[i][0], mat[i][1]);
	}
}