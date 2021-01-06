#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<unsigned long long> pib;
	vector<unsigned long long> cases;

	vector<vector<unsigned long long> > mat;

	unsigned long long cut = 100000000000000000, plus, up;
	int front = 122;

	pib.push_back(0);
	pib.push_back(1);
	pib.push_back(1);

	cases.push_back(0);
	cases.push_back(0);
	cases.push_back(0);

	mat.push_back(pib);

	for (int i = 0; i < front; i++)
	{
		mat.push_back(cases);
	}

	int number;
	cin >> number;


	while (1)
	{
		plus = 0;
		up = 0;

		for (int i = 0; i < mat.size(); i++)
		{
			plus = mat[i][mat[i].size() - 1] + mat[i][mat[i].size() - 2] + up;
			up = 0;
			if (plus > cut)
			{
				up = plus / cut;
				plus = plus % cut;
			}
			mat[i].push_back(plus);
			plus = 0;
		}
		if (mat[mat.size() - 1].size() > number)
			break;
	}
	bool key, isStart;

	key = false;
	isStart = false;
	for (int i = mat.size() - 1; i >= 0; i--)
	{
		if (i == 0 && !key)
			cout << mat[i][number];
		else if (mat[i][number] != 0 && !key)
		{
			key = true;
			isStart = true;
			cout << i << endl;
		}
		if (key)
		{
			if (isStart)
				printf("%llu", mat[i][number]);
			else
				printf("%017llu", mat[i][number]);
		}
		isStart = false;
	}
	cout << endl;
}