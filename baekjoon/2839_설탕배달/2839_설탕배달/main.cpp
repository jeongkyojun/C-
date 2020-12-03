#include<iostream>
using namespace std;
/*
* 3kg 과 5kg 봉지가 있다.
* (3 * x) + (5 * y) = N 가 되는 x,y 순서쌍 중
* x+y가 최소가 되는 순서쌍을 구해라
* -> y가 클수록 x+y는 최소가 된다.
* 1,2,3 내에서 해결된다.
* N % 5 = 0이면 y=N/5	, x=0
* N % 5 = 1이면 y=N/5-1	, x=2
* N % 5 = 2이면 y=N/5-2	, x=4
* N % 5 = 3이면 y=N/5	, x=1
* N % 5 = 4이면 y=N/5-1	, x=3
* 이때, y=0인경우, N%5=1,2,4 인 경우는 -1을 출력해야 한다.
*/
/*
* 풀이 2
* y = N/5이고, etc = N%5;
* if(etc%3 !=0)인 경우 y--, etc+=5,
* 그뒤 다시 덧셈
* y<0이 되면 -1출력, 그전에 통과시 y+(etc/3)
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
