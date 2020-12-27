#include<iostream>
#include<string>
using namespace std;

// (의 수를 확인한다.
// )가 나왔을때, 먼저 (가 있는지 확인한다.
// 있으면 (의 숫자를 하나 줄이고, 없으면 답의 값을 1 늘린다.
// 마지막에 남아있는 (의 수만큼 답에 더한다.
int main()
{
	string str;
	bool isOpen = false;
	getline(cin, str);
	int open_num = 0,res = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			open_num++;
		}
		else if (str[i] == ')')
		{
			if (open_num > 0)
				open_num--;
			else
				res++;
		}
	}
	res += open_num;
	cout << res << endl;
}