#include<iostream>
#include<vector>
using namespace std;
/*
* bfs ����
*/

/*
* 
* �ð��ʰ��� ���� �ּ�ó��
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
	int number; // �̺κ��� �ʿ� ����
	int point;
};

int main()
{
	int num, item;
	vector<int> bridge;
	vector<int> goNum;
	frog frogs[10000]; // �׳� int�� ť�� ����߾ �Ǿ��� ��
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
		// ť���� ���� ������.
		tmp = frogs[++Qtail % Qsize];

		// �ش� �������� �����ŭ ���� ���� ���� Ȯ���Ͽ� ť�� �ִ´�.
		for (int i = bridge[tmp.point]; tmp.point + i < bridge.size(); i += bridge[tmp.point])
		{
			// ���� ����� ���ų� ���Ƚ���� ���ݺ��� �� ���Ҵٸ�
			if (goNum[tmp.point + i] == -1 || goNum[tmp.point + i] > tmp.number+1)
			{
				// ��� Ƚ�� ����
				goNum[tmp.point + i] = tmp.number + 1;
				if (tmp.point + i == b)
					break;
				// ť�� ���� �ִ´�.
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
				// ��� Ƚ�� ����
				goNum[tmp.point - i] = tmp.number + 1;
				if (tmp.point + i == b)
					break;
				// ť�� ���� �ִ´�.
				frogs[++Qhead % Qsize].number = tmp.number + 1;
				frogs[Qhead % Qsize].point = tmp.point - i;
			}
		}
		if (goNum[b] != -1)
			break;
	}
	cout << goNum[b] << endl;
}