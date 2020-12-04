#include<iostream>
#include<vector>
#define MaxNum 1000001
using namespace std;

/*
* 에라토스테네스의 체
* i = 2부터 sqrt(최댓값) 을 찾고,
* 그 수의 제곱부터 시작하여 이후의 배수를 모두 지운다.
*/

void Eratos(bool primeArr[])
{
	//초기화
	for (int i = 2; i < MaxNum; i++)
		primeArr[i] =true;

	//소수가 아닌 값을 false로 바꾼다.
	for (int i = 2; i * i < MaxNum; i++)
	{
		if (primeArr[i])
			for (int j = i * i; j < MaxNum; j += i)
				primeArr[j] = false;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	bool primeArr[MaxNum];
	int m, n;
	cin >> m >> n;
	if (m <= 1)
		m == 2;
	Eratos(primeArr);
	for (int i = m; i <= n; i++)
	{
		if (primeArr[i])
			cout << i << "\n";
	}
}