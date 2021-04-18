#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string num1,num2,res; // 각자 숫자1, 숫자2, 올림수
	res = "";
	getline(cin, num1,' ');
	getline(cin, num2,'\n');

	// 숫자로 변환하기 위해서는 0x30을 빼면 된다.(=48)
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int k = 0;
	int a, b; // 각자 자리수를 숫자로 변환한 값

	string big, small;

	// 두 수 간 자리수를 맞춰준다
	if (i > j)
	{
		big = num1;
		for (j; i > j; j++)
			small += "0";
		small += num2;
	}
	else
	{
		big = num2;
		for (i; j > i; i++)
			small += "0";
		small += num1;
	}
	cout << big<<endl;
	cout << small<<endl;
	i = big.size() - 1;
	while ( i >= 0)
	{
		a = big[i] - 0x30;
		b = small[i] - 0x30;
		cout << a << " , " << b << "  ";

		cout << (a + b + k) << endl;
		res += ((a + b + k) % 10 + 0x30);

		if (a + b + k >= 10)
			k = 1;
		else
			k = 0;
		i--;
	}

	if (k > 0)
	{
		res += k + 0x30;
	}

	reverse(res.begin(), res.end());
	cout << res << endl;
}