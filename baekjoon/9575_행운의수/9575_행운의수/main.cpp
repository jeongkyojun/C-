#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t,at,bt,ct,number;
	
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		set<int> set,a,b,c;
		std::set<int>::iterator it,ita,itb,itc;

		int res = 0;
		cin >> at;
		for (int i = 0; i < at; i++)
		{
			cin >> number;
			a.insert(number);
		}
		cin >> bt;
		for (int i = 0; i < bt; i++)
		{
			cin >> number;
			b.insert(number);
		}
		cin >> ct;
		for (int i = 0; i < ct; i++)
		{
			cin >> number;
			c.insert(number);
		}

		bool key = true;
		for (ita = a.begin();ita!=a.end();++ita)
		{
			for (itb=b.begin();itb!=b.end();++itb)
			{
				for (itc = c.begin();itc!=c.end();++itc)
				{
					set.insert(*ita+*itb+*itc);
				}
			}
		}
		for (it = set.begin(); it != set.end(); ++it)
		{
			int num = *it;
			key = true;
			while (num >= 1)
			{
				if (num % 10 != 5 && num % 10 != 8)
				{
					key = false;
					break;
				}
				num /= 10;
			}
			if (key)
				res++;
		}
		cout <<res << endl;
	}
}