#include<iostream>
using namespace std;
/*
* 3kg �� 5kg ������ �ִ�.
* (3 * x) + (5 * y) = N �� �Ǵ� x,y ������ ��
* x+y�� �ּҰ� �Ǵ� �������� ���ض�
* -> y�� Ŭ���� x+y�� �ּҰ� �ȴ�.
* 1,2,3 ������ �ذ�ȴ�.
* N % 5 = 0�̸� y=N/5	, x=0
* N % 5 = 1�̸� y=N/5-1	, x=2
* N % 5 = 2�̸� y=N/5-2	, x=4
* N % 5 = 3�̸� y=N/5	, x=1
* N % 5 = 4�̸� y=N/5-1	, x=3
* �̶�, y=0�ΰ��, N%5=1,2,4 �� ���� -1�� ����ؾ� �Ѵ�.
*/
/*
* Ǯ�� 2
* y = N/5�̰�, etc = N%5;
* if(etc%3 !=0)�� ��� y--, etc+=5,
* �׵� �ٽ� ����
* y<0�� �Ǹ� -1���, ������ ����� y+(etc/3)
*/
int main()
{
	int N, etc, y;
	cin >> N;
	y = N / 5;
	etc = N%5;
	while (etc%3!=0)
	{
		y--;
		etc += 5;
		if (y < 0)
			break;
	}
	if (y < 0)
		cout << -1 << endl;
	else
		cout << y + (etc / 3) << endl;
}
