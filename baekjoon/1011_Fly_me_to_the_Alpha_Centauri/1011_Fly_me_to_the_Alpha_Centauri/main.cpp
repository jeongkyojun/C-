#include<iostream>
#include<cmath>
using namespace std;

/*
* 여기서 결국 최대한 빨리 가는 방법은
* 1+2+3+...+n+n-1+n-2+...+1 이다.
* 그렇다면 순서대로 했을 때,
* 1 = 1
* 1+1 = 2
* 1+2+1 = 4
* 1+2+2+1 = 6 
* 1+2+3+2+1 = 9
* 1+2+3+3+2+1 = 12
* 1+2+3+4+3+2+1 = 16
* -> 즉 홀수일때는 ((n/2)+1)^2 , 짝수일때는 (n/2)((n/2)+1) 이 된다.
* 즉 해당 경계 안의 숫자를 파악해서 n의 값을 구하면 된다.
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