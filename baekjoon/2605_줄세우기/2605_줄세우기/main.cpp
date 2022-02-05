#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> head_link(101);
	vector<int> tail_link(101);
	int head = 0;
	int t, num;
	int lnk;
	// head_link와 tail_link 의 0번 인덱스는 각자 head와 tail 끝을 의미한다.
	/*
	* 배열을 이용한 양방향 연결 리스트 구현
	*/
	head_link[0] = -1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		// 현재값 : i, i 의 head = head_link[i], tail = tail_link[i]
		lnk = 0;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			lnk = head_link[lnk]; // link = head_link가 가리키는 인덱스로 이동
		}

		if (head_link[lnk] == -1) // 현재 블럭이 마지막인 경우를 의미함
		{
			head = i;
			cout << "head : " << i << endl;
			head_link[lnk] = i;
			tail_link[i] = lnk;
		}
		else
		{
			tail_link[head_link[lnk]] = i;
			head_link[i] = head_link[lnk]; // 현재값의 head에 head_link[lnk]값 부여
			head_link[lnk] = i;//현재값을 이어붙인다.
			//tail_link[lnk]는 그대로
			tail_link[i] = lnk; // 현재값의 tail을 이어붙인다.
		}
	}
	lnk = 0;
	for (int j = 0; j < t; j++)
	{
		cout << tail_link[lnk] << " ";
		lnk = tail_link[lnk];
	}
	cout << endl;
}