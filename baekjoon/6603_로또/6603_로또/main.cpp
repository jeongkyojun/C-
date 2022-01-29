#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void lotto(vector<int>& vec, vector<int> v, int point, int i)
{
	if (point != 0)
		v.push_back(vec[i]);
	if (point == 6)
	{
		for (int i = 0; i < point-1; i++)
		{
			cout << v[i] << " ";
		}
		cout << v[point - 1]<<endl;
		cout << endl;
	}
	for (int p = i+1; p < vec.size(); p++)
	{
		lotto(vec, v, point + 1, p);
	}
}

int main()
{
	vector<int> vec, v;
	int num,x;

	while (true)
	{
		vec.clear();
		v.clear();
		cin >> num;
		if (num == 0)
			break;
		for (int i = 0; i < num; i++)
		{
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		lotto(vec, v, 0, -1);
		cout << endl;
	}
}