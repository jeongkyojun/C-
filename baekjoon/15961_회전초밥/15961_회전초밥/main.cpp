#include<iostream>
#include<vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int plate[30001];// 메모리문제때문에 배열크기 줄임
	int isEat[3001];
	int head, tail, eat = 0;
	int N, d, k, c, menu, max = -1;
	for (int i = 0; i <= 3000; i++)
	{
		isEat[i] = 0;
	}

	cin >> N >> d >> k >> c; // 접시개수, 가지수, 연속으로 먹는개수, 쿠폰번호

	for (int i = 0; i < N; i++)
	{
		cin >> plate[i];
	}

	for (int i = 0; i < k; i++)
	{
		// 만약 먹어본적 없는 음식이면
		if (isEat[plate[i]] == 0)
			eat++;//+1
		isEat[plate[i]]++; // 모든 메뉴는 기록
	}
	max = eat; // max의 값 : 첫항
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