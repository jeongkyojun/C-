#include<iostream>
#include<string>

using namespace std;
/*
* L�� R�� �ִ� �ڸ����� �����ؾ� �ϸ�
* Ex) 999... �� �ع����� ������ 0�� ����
* 
* �� �ڸ��� ���ڰ� ��ġ�ϰ�, 8�̾�ߵȴ�.
* Ex) 10�� �ڸ��� Ʋ���� 09��, 100�� �ڸ��� Ʋ���� 099 ������ �� ���� �ڸ����� 0�̵ȴ�.
*/

int main()
{
	string L, R;
	int res = 0;
	cin >> L >> R;
	if (L.size() == R.size())
	{
		for (int i = 0; i < R.size(); i++)
		{
			if (L[i] == '8' && R[i] == '8')
				res++;

			if (L[i] != R[i])
				break;
		}
	}
	cout << res << endl;
}
