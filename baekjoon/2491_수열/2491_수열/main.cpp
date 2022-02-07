#include<iostream>

using namespace std;

int main()
{
	int v[100001][2]; // [][0] 은 큰 수 [][1]은 작은수
	int len, num,before = 0;
	int max_num = 1;
	cin >> len;
	v[0][0] = 1;
	v[0][1] = 1;
	cin >> num;
	before = num;
	for (int i = 1; i < len; i++)
	{
		cin >> num;
		if (before <= num)
		{
			v[i][0] = v[i - 1][0] + 1;
			if (max_num < v[i][0])
				max_num = v[i][0];
		}
		else
			v[i][0] = 1;
		if (before >= num)
		{
			v[i][1] = v[i - 1][1] + 1;
			if (max_num < v[i][1])
				max_num = v[i][1];
		}
		else
			v[i][1] = 1;
		before = num;
	}
	cout << max_num << endl;
}