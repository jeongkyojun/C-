#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string num1,num2,res; // ���� ����1, ����2, �ø���
	res = "";
	getline(cin, num1,' ');
	getline(cin, num2,'\n');

	// ���ڷ� ��ȯ�ϱ� ���ؼ��� 0x30�� ���� �ȴ�.(=48)
	int i = num1.size() - 1;
	int j = num2.size() - 1;
	int k = 0;
	int a, b; // ���� �ڸ����� ���ڷ� ��ȯ�� ��

	string big, small;

	// �� �� �� �ڸ����� �����ش�
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