#include<iostream>
#include<cmath>
using namespace std;

/*
* 1�� �̵����
* 1,a -> 1,c��
* 
* 2�� �̵����
* 1,a -> 1,b
* 2,a -> 2,c
* 1,b -> 1,c
*  ��, 1(a,c,b) , 2(a->c) , 1(b,a,c)
* 3�� �̵� ���
* 1,a -> 1,c
* 2,a -> 2,b
* 1,b -> 1,b
* 3,a -> 3,c
* 1,b -> 1,a
* 2,b -> 2,c
* 1,a -> 1,c
*  ��, 2(a,c,b) , 3(a->c) , 2(b,a,c)
* 
* �̿Ͱ��� �ϳ���ž�� �̵������� ��ͷ� ���� �� �ִ�.
* ���� : 1, 1+1+1 , 3+1+3 , 7+1+7 .... 
* 
* 0, 1, 2+1 , 4+2+1, 8+4+2+1 -> 2^n-1 (1,3,7,15,...) 
*/

void hanoi(int a, int b, int c,int n)
{
	if (n > 0)
	{
		hanoi(a, c, b, n - 1);
		printf("%d %d\n", a, c);
		// cout�� �̿��ϸ� ����� �����Ƿ� printf�� �� ��!
		hanoi(b, a, c, n - 1);
	}
}

int main()
{
	int n;
	int res = 0;
	cin >> n;
	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(1, 2, 3, n);
}