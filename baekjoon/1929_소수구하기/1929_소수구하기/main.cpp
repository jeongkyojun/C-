#include<iostream>
#include<vector>
#define MaxNum 1000001
using namespace std;

/*
* �����佺�׳׽��� ü
* i = 2���� sqrt(�ִ�) �� ã��,
* �� ���� �������� �����Ͽ� ������ ����� ��� �����.
*/

void Eratos(bool primeArr[])
{
	//�ʱ�ȭ
	for (int i = 2; i < MaxNum; i++)
		primeArr[i] =true;

	//�Ҽ��� �ƴ� ���� false�� �ٲ۴�.
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