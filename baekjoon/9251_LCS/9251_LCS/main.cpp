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
	* ���� AtoB �� ���� �����ϳ�, 
	* ���� ������ ���� ������ ������ �ִ°� ���� ����
	* �ֵ��� ���� tmp�� ���� AtoB��� ��� �� AtoB�� �����ϴ� ����� ����ߴ�.
	* 
	* �� �ڸ� ���� ��������, �������� ��� ��, 
	* ���� ��ġ�ϴ� �ڸ����� �� ���� �ڸ������� �ִ��� Ȯ��, 
	* �� �� +1 �� ���� ��ġ�ϴ� �ڸ��� �����Ѵ�.
	*/
	for (int i = 0; i < Alen; i++)
	{
		tmp = AtoB;
		cout << i << endl;
		for (int j = 0; j < Blen; j++)
		{
			if (B[j] == A[i]) // B�� A�� ���� ��, ��ġ�ϸ�
			{
				for (int k = 0; k < j; k++)
				{
					if (maxVal < AtoB[k])
					{
						maxVal = AtoB[k];
					}
				}
				tmp[j] = maxVal + 1;//���� �ڸ��� ���� ũ�� �� ���ִ� ���� ����Ͽ� �����Ѵ�.
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