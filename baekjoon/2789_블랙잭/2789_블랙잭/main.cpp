#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int m, n,num,min,res;
	vector<int> cards;
	cin >> m;
	cin >> n;
	
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cards.push_back(num);
	}
	res = 0;
	min = n; // 0ÀÏ°æ¿ì
	for (int i = 0; i < m-2; i++)
	{
		for (int j = i+1; j < m - 1; j++)
		{
			for (int k = j+1; k < m; k++)
			{
				if (cards[i] + cards[j] + cards[k] > n)
				{
					continue;
				}
				else if (n-(cards[i] + cards[j] + cards[k]) <= min)
				{
					min = n - (cards[i] + cards[j] + cards[k]);
					res = cards[i] + cards[j] + cards[k];
				}
				if (min == 0)
				{
					cout << res<<endl;
					return 0;
				}
			}
		}
	}
	cout << res << endl;
}