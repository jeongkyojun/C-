#include<iostream>
#include<cmath>
using namespace std;

/*
* ���⼭ �ᱹ �ִ��� ���� ���� �����
* 1+2+3+...+n+n-1+n-2+...+1 �̴�.
* �׷��ٸ� ������� ���� ��,
* 1 = 1
* 1+1 = 2
* 1+2+1 = 4
* 1+2+2+1 = 6 
* 1+2+3+2+1 = 9
* 1+2+3+3+2+1 = 12
* 1+2+3+4+3+2+1 = 16
* -> �� Ȧ���϶��� ((n/2)+1)^2 , ¦���϶��� (n/2)((n/2)+1) �� �ȴ�.
* �� �ش� ��� ���� ���ڸ� �ľ��ؼ� n�� ���� ���ϸ� �ȴ�.
*/

int main()
{
	int a, b, length;
	int T, count = 1, result = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		length = b - a;
		count = sqrt(length);
		if (length > count * count)
			count++;
		result = (count * 2) - 1;
		if (length <= ((count * count) - count))
			result -= 1;
		cout << result << endl;
	}
}