#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>sub;
	string nums;
	int prenum = 0, sufnum = 0, res = 0;
	cin >> nums;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == '+')
		{
			prenum += sufnum;
			sufnum = 0;
		}
		else if (nums[i] == '-')
		{
			prenum += sufnum;
			sub.push_back(prenum);
			prenum = 0;
			sufnum = 0;
		}
		else
		{
			sufnum *= 10;
			sufnum += nums[i]-0x30;
		}
	}
	sub.push_back(sufnum+prenum);
	res = sub[0];
	for (int i = 1; i < sub.size(); i++)
	{
		res -= sub[i];
	}
	cout << res << endl;
}