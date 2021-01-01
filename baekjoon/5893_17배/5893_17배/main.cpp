#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str,res;
	string str2="0000";
	bool isUp=false;
	getline(cin, str);
	str2 += str;
	str += "0000";

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == '1' && str2[i] == '1')
		{
			if (isUp)
				res += '1';
			else
				res += '0';
			isUp = true;
		}
		else if (str[i] == '0' && str2[i] == '1')
		{
			if (isUp)
			{
				res += '0';
				isUp = true;
			}
			else
			{
				res += '1';
				isUp = false;
			}
		}
		else if (str[i] == '1' && str2[i] == '0')
		{
			if (isUp)
			{
				res += '0';
				isUp = true;
			}
			else
			{
				res += '1';
				isUp = false;
			}
		}
		else if(str[i] == '0' && str2[i]=='0')
		{
			if (isUp)
				res += '1';
			else
				res += '0';
			isUp = false;
		}
	}
	if (isUp)
		res += '1';
	reverse(res.begin(), res.end());
	int point=0;
	string result;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] != '0')
		{
			point = i;
			break;
		}
	}
	for (int i = point; i < res.size(); i++)
	{
		result+=res[i];
	}
	cout << result << endl;
}