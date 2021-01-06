#include<iostream>
#include<vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int plate[30001];// �޸𸮹��������� �迭ũ�� ����
	int isEat[3001];
	int head, tail, eat = 0;
	int N, d, k, c, menu, max = -1;
	for (int i = 0; i <= 3000; i++)
	{
		isEat[i] = 0;
	}

	cin >> N >> d >> k >> c; // ���ð���, ������, �������� �Դ°���, ������ȣ

	for (int i = 0; i < N; i++)
	{
		cin >> plate[i];
	}

	for (int i = 0; i < k; i++)
	{
		// ���� �Ծ�� ���� �����̸�
		if (isEat[plate[i]] == 0)
			eat++;//+1
		isEat[plate[i]]++; // ��� �޴��� ���
	}
	max = eat; // max�� �� : ù��
	if (isEat[c] == 0)
		max++;
	if (k != N)
	{
		for (head = 0; head < N; head++)
		{

			tail = (head + k - 1) % N;
			if (isEat[c] == 0)
			{
				if (max < eat + 1)
					max = eat + 1;
			}
			else
			{
				if (max < eat)
					max = eat;
			}


			isEat[plate[head]]--;
			if (isEat[plate[head]] == 0)
			{
				eat--;
			}
			if (tail == N - 1)
			{
				isEat[plate[0]]++;
				if (isEat[plate[0]] == 1)
				{
					eat++;
				}
			}
			else
			{
				isEat[plate[tail + 1]]++;
				if (isEat[plate[tail + 1]] == 1)
				{
					eat++;
				}
			}

		}
	}
	cout << max << endl;
}