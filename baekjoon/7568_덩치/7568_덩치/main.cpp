#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> info(3);
	vector<vector<int> >mat;
	int num;
	int w,h;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> w >> h;
		info[0] = w;
		info[1] = h;
		info[2] = 1;
		mat.push_back(info);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j < num; j++)
		{
			if (mat[i][0] < mat[j][0] && mat[i][1] < mat[j][1])
				mat[i][2]++;
			else if(mat[i][0] > mat[j][0] && mat[i][1] > mat[j][1])
				mat[j][2]++;
		}
	}
	for (int i = 0; i < mat.size(); i++)
	{
		cout << mat[i][2] << " ";
	}
	cout << endl;
}