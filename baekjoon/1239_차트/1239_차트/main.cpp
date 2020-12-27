#include<iostream>
#include<vector>
using namespace std;

void inputNum(vector<vector<int> > &mat, vector<int>vec,vector<bool>vec2,int num,int maxnum,int arr[],int number)
{
	vec2[number] = false;
	vec.push_back(arr[number]);
	if (num < maxnum-1)
	{
		for (int i = 0; i < maxnum; i++)
		{
			if (vec2[i])
				inputNum(mat, vec,vec2, num + 1, maxnum,arr,i);
		}
	}
	else
	{
		mat.push_back(vec);
	}
}


int main()
{
	vector<int>vec;
	vector<bool>vec2(8);
	vector<vector<int> > mat;
	int arr[8];
	int n, num, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vec2[i] = true;
		cin >> num;
		arr[i] = num;
	}
	for (int i = 0; i < n; i++)
	{
		inputNum(mat, vec,vec2, 0, n, arr,i);
	}
	for (int a = 0; a < mat.size(); a++)
	{
		int nums=0;
		for (int i = 0; i < n-1; i++)
		{
			mat[a][i + 1] = mat[a][i] + mat[a][i + 1];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (mat[a][i] + 50 == mat[a][j])
				{
					nums++;
					break;
				}
				else if (mat[a][i] < mat[a][j] - 50)
					break;
			}
		}
		if (nums > res)
			res = nums;
		if (res == n / 2)
			break;
	}
	cout << res;
}