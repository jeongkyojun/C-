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
	// head_link�� tail_link �� 0�� �ε����� ���� head�� tail ���� �ǹ��Ѵ�.
	/*
	* �迭�� �̿��� ����� ���� ����Ʈ ����
	*/
	head_link[0] = -1;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		// ���簪 : i, i �� head = head_link[i], tail = tail_link[i]
		lnk = 0;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			lnk = head_link[lnk]; // link = head_link�� ����Ű�� �ε����� �̵�
		}

		if (head_link[lnk] == -1) // ���� ���� �������� ��츦 �ǹ���
		{
			head = i;
			cout << "head : " << i << endl;
			head_link[lnk] = i;
			tail_link[i] = lnk;
		}
		else
		{
			tail_link[head_link[lnk]] = i;
			head_link[i] = head_link[lnk]; // ���簪�� head�� head_link[lnk]�� �ο�
			head_link[lnk] = i;//���簪�� �̾���δ�.
			//tail_link[lnk]�� �״��
			tail_link[i] = lnk; // ���簪�� tail�� �̾���δ�.
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