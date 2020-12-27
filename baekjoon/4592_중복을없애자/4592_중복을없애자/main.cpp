#include<iostream>

using namespace std;

int main()
{
	int arr[26], cnt = 0;
	int num;
	int bef = -1,number;
	while (true)
	{
		cin >> num;
		if (num == 0)
			break;
		for (int i = 0; i < num; i++)
		{
			cin >> number;
			if (number == bef)
			{
				continue;
			}
			else
			{
				arr[cnt++] = number;
			}
			bef = number;
		}
		for (int i = 0; i < cnt; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "$" << endl;
		cnt = 0;
	}
}