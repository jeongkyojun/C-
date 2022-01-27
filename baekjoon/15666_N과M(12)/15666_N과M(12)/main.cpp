#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void N_M(vector<int>& vec, vector<int>v, int dot, int point, int M)
{
	if (point != 0)
		v.push_back(vec[dot]);
	if(point == M)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
			//printf("%d ",v[i]);
		}
		cout << endl;
		//printf("\n");
	}
	else
	{
		for(int i=dot;i<vec.size();i++)
		{
			N_M(vec, v,i, point + 1, M);
		}
	}
}

int main()
{
	int N, M;
	int num;
	bool isIn = false;
	vector<int> v,v_r;

	cin >> N;
	cin >> M;
	//scanf("%d%d",&N,&M);

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		//scanf("%d",&num);
		isIn = false;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == num)
			{
				isIn = true;
				break;
			}
		}
		if(!isIn)
			v.push_back(num);
	}
	sort(v.begin(), v.end());
	N_M(v, v_r, 0, 0, M);
}