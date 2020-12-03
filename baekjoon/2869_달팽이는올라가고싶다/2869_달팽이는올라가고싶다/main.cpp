#include<iostream>
using namespace std;

/*
* 높이 V , 올라가는 값 A, 내려가는 값 B
* 지금까지 올라온 높이 X
* X+=A 
* 만약 X<V면 n++ , X-=B
* 아니면 거기서 끝
* -> 시간초과
*/
/*
* 풀이 2
* 맨 처음 올라간다 -> 이후 떨어지고 올라가는것을 반복한다.
* V <= An - B(n-1) ->  V -B <= (A-B)n
* 2 1 5 -> 4 <= 1n
* 5 1 6 -> 5 <= 4n
* 100 99 1000000000 -> 999999901 <= n
* 
*/
int main()
{
	int V, A, B, X,day=0;
	X = 0;
	cin >> A >> B >> V;
	V -= B;
	// V <= (A-B)*day
	// V/(A-B) <= day
	day = V / (A - B);
	if (V % (A - B))
	{
		day += 1;
	}
	cout << day;
}