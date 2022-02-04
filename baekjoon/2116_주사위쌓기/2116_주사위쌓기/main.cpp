#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T,num,max = -1, sum = 0;
	int l[6] = { 0,1,2,4,5,3 };
	vector<int> dice(6);
	vector<vector<int>>mat,root;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		root.push_back(dice); // 경로를 저장하는 2차원 벡터
		mat.push_back(dice); // 값을 저장하는 2차원 벡터
	}
	// root와 mat 채우기
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> dice[l[j]];
		}
		for (int j = 0; j < 6; j++)
		{
			root[i][dice[j] - 1] = dice[(j + 3) % 6]-1;
			if (dice[j] == 6||dice[(j+3)%6]==6)
			{
				if (dice[j] == 5 || dice[(j + 3) % 6] == 5)
				{
					mat[i][dice[j]-1] = 4;
					mat[i][dice[(j + 3) % 6]-1] = 4;
				}
				else
				{
					mat[i][dice[j]-1] = 5;
					mat[i][dice[(j + 3) % 6]-1] = 5;
				}
			}
			else
			{
				mat[i][dice[j]-1] = 6;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < 6; j++)
		{
			cout << root[i][j] << " ";
		}
		cout << endl;
	}
	
	int start;
	for (int i = 0; i < 6; i++)
	{
	
		start = i;
		sum = 0;
		cout <<"case : "<<endl<< start;
		for (int j = 0; j < T; j++)
		{
			sum += mat[j][start];
			start = root[j][start];
			cout << "-" << start;
		}
		cout << " ::::: sum = "<<sum<<endl;
		if (max < sum)
			max = sum;
	}
	cout << max<<endl;
}