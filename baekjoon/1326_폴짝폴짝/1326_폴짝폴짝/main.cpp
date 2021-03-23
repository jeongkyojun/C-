#include<iostream>
#include<vector>
using namespace std;
/*
* bfs 문제
*/

/*
* 
* 시간초과로 인해 주석처리
* 
void addBridge(vector<int>& goNum, vector<int>& bridge, vector<bool>&isGo, int point)
{
	for (int i = bridge[point]; point + i < bridge.size(); i += bridge[point])
	{
		if (goNum[point + i] == -1 || goNum[point + i] > goNum[point] + 1)
		{
			goNum[point + i] = goNum[point] + 1;
		}
	}

	for (int i = bridge[point]; point - i > 0; i += bridge[point])
	{
		if (goNum[point - i] == -1 || goNum[point - i] > goNum[point] + 1)
		{
			goNum[point - i] = goNum[point] + 1;
		}
	}

	addBridge(goNum, bridge, isGo, point + i);

}
*/

struct frog 
{
	int number; // 이부분은 필요 없음
	int point;
};

int main()
{
	int num, item;
	vector<int> bridge;
	vector<int> goNum;
	frog frogs[10000]; // 그냥 int형 큐를 사용했어도 되었을 것
	int Qhead = -1;
	int Qtail = -1;
	int Qsize = 10000;

	cin >> num;
	bridge.push_back(0);
	goNum.push_back(-1);
	for (int i = 1; i < num + 1; i++)
	{
		cin >> item;
		bridge.push_back(item);
		goNum.push_back(-1);
	}

	int a, b;
	cin >> a >> b;
	goNum[a] = 0;
	frogs[++Qhead % Qsize].number = goNum[a];
	frogs[Qhead % Qsize].point = a;

	frog tmp;
	while (Qhead>Qtail)
	{
		// 큐에서 값을 꺼낸다.
		tmp = frogs[++Qtail % Qsize];

		// 해당 지점에서 배수만큼 더한 값을 각자 확인하여 큐에 넣는다.
		for (int i = bridge[tmp.point]; tmp.point + i < bridge.size(); i += bridge[tmp.point])
		{
			// 아직 디딘적 없거나 디딘횟수가 지금보다 더 많았다면
			if (goNum[tmp.point + i] == -1 || goNum[tmp.point + i] > tmp.number+1)
			{
				// 디딘 횟수 변경
				goNum[tmp.point + i] = tmp.number + 1;
				if (tmp.point + i == b)
					break;
				// 큐에 값을 넣는다.
				frogs[++Qhead % Qsize].number = tmp.number+1;
				frogs[Qhead % Qsize].point = tmp.point + i;
			}
		}
		if (goNum[b] != -1)
			break;
		for (int i = bridge[tmp.point]; tmp.point - i > 0; i += bridge[tmp.point])
		{
			if (goNum[tmp.point - i] == -1 || goNum[tmp.point - i] > tmp.number + 1)
			{
				// 디딘 횟수 변경
				goNum[tmp.point - i] = tmp.number + 1;
				if (tmp.point + i == b)
					break;
				// 큐에 값을 넣는다.
				frogs[++Qhead % Qsize].number = tmp.number + 1;
				frogs[Qhead % Qsize].point = tmp.point - i;
			}
		}
		if (goNum[b] != -1)
			break;
	}
	cout << goNum[b] << endl;
}