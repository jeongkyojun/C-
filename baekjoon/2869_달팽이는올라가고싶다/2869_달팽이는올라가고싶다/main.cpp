#include<iostream>
using namespace std;

/*
* ���� V , �ö󰡴� �� A, �������� �� B
* ���ݱ��� �ö�� ���� X
* X+=A 
* ���� X<V�� n++ , X-=B
* �ƴϸ� �ű⼭ ��
* -> �ð��ʰ�
*/
/*
* Ǯ�� 2
* �� ó�� �ö󰣴� -> ���� �������� �ö󰡴°��� �ݺ��Ѵ�.
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