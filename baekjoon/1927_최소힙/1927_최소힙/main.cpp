#include<iostream>

using namespace std;
/*
* 자연수면 배열에 넣는다
* 0이면 가장 작은값을 출력 및 제거한다.
* 연산의 갯수는 최대 10만개
* 자연수 값은 int 최대범위 까지
*/
int main()
{
	//0 -> 1,2 -> 3,4,5,6...
	// n의 자식들은 2n+1, 2n+2
	// n의 부모는 (n-1)/2;
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
					if (arr[2 * child + 1] != -1 && arr[2 & child + 2] != -1) // 둘다 차있는경우
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
					else if (arr[2 * child + 1] != -1) // 하나만 차있는경우 -> 거기다 넣는다.
					{
						tmp = arr[2 * child + 1];
						arr[2 * child + 1] = arr[child];
						arr[child] = tmp;

						child = 2 * child + 1;
					}
					else // 둘다 비어있다 -> 나간다.
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