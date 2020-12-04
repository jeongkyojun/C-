#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec_Prime;
	int m, n;
	int res = 0, min = 10001;
	cin >> m >> n;
	bool key;
	if (m == 1)
		m = 2;
	for (int i = 2; i < m; i++)
	{
		key = true;
		for (int j = 0; j < vec_Prime.size(); j++)
		{
			if (i % vec_Prime[j] == 0)
			{
				key = false;
				break;
			}
		}
		if (key)
		{
			vec_Prime.push_back(i);
		}
	}
	for (int i = m; i <= n; i++)
	{
		key = true;
		for (int j = 0; j < vec_Prime.size(); j++)
		{
			if (i % vec_Prime[j] == 0)
			{
				key = false;
				break;
			}
		}
		if (key)
		{
			vec_Prime.push_back(i);
			if (min > i)
				min = i;
			res += i;
		}
	}
	if (res == 0)
		cout << "-1" << endl;
	else
	{
		cout << res << endl;
		cout << min << endl;
	}
}