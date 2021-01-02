#include<iostream>
#include<string>

using namespace std;
/*
* L과 R의 최대 자리수가 동일해야 하며
* Ex) 999... 로 해버리면 무조건 0이 나옴
* 
* 각 자리의 숫자가 일치하고, 8이어야된다.
* Ex) 10의 자리가 틀리면 09로, 100의 자리가 틀리면 099 등으로 그 이하 자리수는 0이된다.
*/

int main()
{
	string L, R;
	int res = 0;
	cin >> L >> R;
	if (L.size() == R.size())
	{
		for (int i = 0; i < R.size(); i++)
		{
			if (L[i] == '8' && R[i] == '8')
				res++;

			if (L[i] != R[i])
				break;
		}
	}
	cout << res << endl;
}
