#include<iostream>
#include<string>
using namespace std;

// (�� ���� Ȯ���Ѵ�.
// )�� ��������, ���� (�� �ִ��� Ȯ���Ѵ�.
// ������ (�� ���ڸ� �ϳ� ���̰�, ������ ���� ���� 1 �ø���.
// �������� �����ִ� (�� ����ŭ �信 ���Ѵ�.
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