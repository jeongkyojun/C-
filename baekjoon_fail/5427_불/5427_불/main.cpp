#include<iostream>
#include<vector>
using namespace std;

void findRoute(int &minimum, int turn, vector<vector<int> >mati,int x,int y, vector<vector<int> >fps)
{
	if (x == 0 || y == 0||x==mati.size()-1||y==mati[x].size()-1)
	{
		if (minimum > turn+1)
		{
			minimum = turn+1;
		}
	}
	else
	{
		int min;
		if (mati[x + 1][y] != -1)
		{
			//
			//		4	5	6
			//		3	4	5
			//		2	3	4
			//	0	1	2	3	-> x,y �� �� �� ������ +2, �ƴϸ� ��ȭ ����

			min = 2000;
			for (int i = 0; i < fps.size(); i++)
			{
				int route = abs(fps[i][1] - x) + abs(fps[i][0] - y);
				if (fps[i][1] < x + 1) // x�� ���� ������
				{
					if (mati[fps[i][1] + 1][fps[i][0]] == -1) // �������
					{
						//y �� ����������
						if (fps[i][0] < y)
						{
							if (mati[fps[i][1]][fps[i][0]+1] == -1)
							{
								route += 2;
							}
						}
						else if(fps[i][0]>y)
						{
							if (mati[fps[i][1]][fps[i][0] - 1] == -1)
							{
								route += 2;
							}
						}
					}
				}
				else if(fps[i][1]>x+1)
				{
					if (mati[fps[i][1] - 1][fps[i][0]] == -1)
					{
						if (fps[i][0] < y)
						{
							if (mati[fps[i][1]][fps[i][0] + 1] == -1)
							{
								route += 2;
							}
						}
						else if (fps[i][0] > y)
						{
							if (mati[fps[i][1]][fps[i][0] - 1] == -1)
							{
								route += 2;
							}
						}
					}
				}
				else
				{
					//�������� y�� ���������� ������ �ȴ�.
					if (fps[i][0] < y)
					{
						if (mati[fps[i][1]][fps[i][0] + 1] == -1)
						{
							route += 2;
						}
					}
					else if (fps[i][0] > y)
					{
						if (mati[fps[i][1]][fps[i][0] - 1] == -1)
						{
							route += 2;
						}
					}
				}
			}
		}
		if (mati[x - 1][y] != -1)
		{
			
		}
		if (mati[x][y+1] != -1)
		{

		}
		if (mati[x][y-1] != -1)
		{

		}
		mati[x][y] = -1;
		if (x<mati.size()-1 && mati[x + 1][y] > turn)
		{
			findRoute(minimum, turn + 1, mati, x + 1, y,fps);
		}
		if (x>0 && mati[x - 1][y] > turn)
		{
			findRoute(minimum, turn + 1, mati, x - 1, y,fps);
		}
		if (y<mati[x].size() - 1 && mati[x][y+1] > turn)
		{
			findRoute(minimum, turn + 1, mati, x, y+1,fps);
		}
		if (y>0 && mati[x][y-1] > turn)
		{
			findRoute(minimum, turn + 1, mati, x , y-1,fps);
		}
	}
}

int main()
{
	int t,row,col;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		vector<int>fp(2);
		vector<vector<int> > fps;
		cin >> row >> col;
		vector<char> vec(row);
		vector<vector<char> > mat;
		vector<int> veci(row);
		vector<vector<int> > mati;
		int minimum = 2000,posx,posy;
		for (int j = 0; j < col; j++)
		{
			for (int i = 0; i < row; i++)
			{
				cin >> vec[i];
				if (vec[i] == '*')
				{
					fp[0] = i;
					fp[1] = j;
					fps.push_back(fp);
				}
			}
			mat.push_back(vec);
		}
		for (int j = 0; j < col; j++)
		{
			for (int i = 0; i < row; i++)
			{
				if (mat[j][i] == '#')
				{
					veci[i] = -1;
				}
				else if (mat[j][i] == '*')
				{
					veci[i] = 0;
				}
				else
				{
					if (mat[j][i] == '@')
					{
						posx = j;
						posy = i;
					}
					veci[i] = 2000;
				}
			}
			mati.push_back(veci);
		}

		findRoute(minimum, 0, mati, posx, posy,fps);
		if (minimum == 2000)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << minimum<<endl;
	}
}