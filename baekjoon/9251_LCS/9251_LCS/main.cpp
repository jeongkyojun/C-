#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<int> AtoB(1001),tmp(1001);
	string A, B;
	int Alen, Blen;
	int max = 0;
	int maxVal = 0;
	getline(cin, A);
	getline(cin, B);
	Alen = A.size();
	Blen = B.size();

	for (int i = 0; i < Blen; i++)
	{
		AtoB[i] = 0;
	}
	/*
	* 벡터 AtoB 에 값을 저장하나, 
	* 현재 수행한 값이 이전에 영향을 주는걸 막기 위해
	* 쌍둥이 벡터 tmp를 만들어서 AtoB대신 계산 후 AtoB에 적용하는 방식을 사용했다.
	* 
	* 각 자리 별로 비교했을때, 이전까지 결과 중, 
	* 현재 일치하는 자리보다 더 작은 자리에서의 최댓값을 확인, 
	* 그 값 +1 을 현재 일치하는 자리에 적용한다.
	*/
	for (int i = 0; i < Alen; i++)
	{
		tmp = AtoB;
		cout << i << endl;
		for (int j = 0; j < Blen; j++)
		{
			if (B[j] == A[i]) // B와 A의 값을 비교, 일치하면
			{
				for (int k = 0; k < j; k++)
				{
					if (maxVal < AtoB[k])
					{
						maxVal = AtoB[k];
					}
				}
				tmp[j] = maxVal + 1;//현재 자리에 가장 크게 올 수있는 값을 계산하여 적용한다.
				if (maxVal + 1 > max)
					max = maxVal + 1;
			}
			for (int k = 0; k < Blen; k++)
			{
				cout << tmp[k] << " ";
			}
			cout << endl;
			maxVal = 0;
		}
		AtoB = tmp;
	}
	cout << max << endl;
}