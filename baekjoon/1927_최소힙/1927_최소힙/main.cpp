#include<iostream>

using namespace std;
/*
* �ڿ����� �迭�� �ִ´�
* 0�̸� ���� �������� ��� �� �����Ѵ�.
* ������ ������ �ִ� 10����
* �ڿ��� ���� int �ִ���� ����
*/
int main()
{
	//0 -> 1,2 -> 3,4,5,6...
	// n�� �ڽĵ��� 2n+1, 2n+2
	// n�� �θ�� (n-1)/2;
	int arr[100001];
	int size = -1;

	int num, x;
	for (int i = 0; i < 100001; i++)
	{
		arr[i] = -1;
	}
	cin >> num;
	int child,tmp;
	for (int i = 0; i < num; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (size == -1)
			{

			}
			else
			{
				cout << arr[0] << endl;
				child = 0;
				while (child < size)
				{
					if (arr[2 * child + 1] != -1 && arr[2 & child + 2] != -1) // �Ѵ� ���ִ°��
					{
						if (arr[2 * child + 1] < arr[2 * child + 2])
						{
							tmp = arr[2 * child + 1];
							arr[2 * child + 1] = arr[child];
							arr[child] = tmp;

							child = 2 * child + 1;
						}
						else
						{
							tmp = arr[2 * child + 2];
							arr[2 * child + 2] = arr[child];
							arr[child] = tmp;

							child = 2 * child + 2;
						}
					}
					else if (arr[2 * child + 1] != -1) // �ϳ��� ���ִ°�� -> �ű�� �ִ´�.
					{
						tmp = arr[2 * child + 1];
						arr[2 * child + 1] = arr[child];
						arr[child] = tmp;

						child = 2 * child + 1;
					}
					else // �Ѵ� ����ִ� -> ������.
						break;
				}
				size--;
			}
		}
		else
		{
			arr[++size] = x;
			child = size;
			while (size != 0)
			{
				if (arr[(child - 1) / 2] > arr[size])
				{
					tmp = arr[size];
					arr[size] = arr[(child - 1) / 2];
					arr[(child - 1) / 2] = tmp;
					child = (child - 1) / 2;
				}
				else
					break;
			}
		}
	}
}