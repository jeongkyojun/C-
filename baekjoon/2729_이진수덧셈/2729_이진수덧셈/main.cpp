#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string num1, num2,tmp;
	int N;
	bool isUp;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string res = "";
		num2 = "";
		cin >> num1 >> tmp;
		if (num1.size() > tmp.size())
		{
			for (int j = 0; j < num1.size() - tmp.size(); j++)
			{
				num2 += "0";
			}
			num2 += tmp;
		}
		else if(num1.size()<tmp.size())
		{
			for (int j = 0; j < tmp.size() - num1.size(); j++)
			{
				num2 += "0";
			}
			num2 += num1;
			num1 = tmp;
		}
		else
		{
			num2 = tmp;
		}
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		isUp = false;

		for (int j = 0; j < num1.size(); j++)
		{
			if (num1[j] == '0') // 0, 0
			{
				if (num2[j] == '0')
				{
					if (isUp) // 0 0 1
						res += '1';
					else // 0 0 0
						res += '0';
					isUp = false;
				}
				else	// 0 , 1
				{
					if (isUp) // 0 1 1
					{
						res += '0';
						isUp = true;
					}
					else // 0 1 0
					{
						res += '1';
						isUp = false;
					}
				}
			}
			else 
			{
				if (num2[j] == '0')  // 1, 0
				{
					if (isUp) // 1 0 1
					{
						res += '0';
						isUp = true;
					}
					else // 1 0 0
					{
						res += '1';
						isUp = false;
					}
				}
				else // 1, 1
				{
					if (isUp) // 1 1 1
						res += '1';
					else // 1 1 0
						res += '0';
					isUp = true;
				}
			}
		}
		if (isUp)
			res += '1';

		reverse(res.begin(), res.end());

		bool isStart = false;

		//맨 처음이 0인 경우는 생략, 전체가 0으로 이루어진 경우는 마지막만 출력
		for (int a = 0; a < res.size(); a++)
		{
			if (res[a] == '1')
				isStart = true;

			if(isStart)
				cout << res[a];

			if (!isStart && a == res.size() - 1)
				cout << res[a];
		}
		cout << endl;
	}
	
}