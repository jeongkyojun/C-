#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec;

	int num,N,max = -1001;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
		{
			vec.push_back(num);
		}
		else
		{
			if (vec[i - 1] > 0)
				num += vec[i - 1];
			vec.push_back(num);
		}
		if (max < num)
			max = num;
	}
	cout << max;
}