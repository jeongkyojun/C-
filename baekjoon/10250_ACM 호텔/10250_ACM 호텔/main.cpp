#include<iostream>

using namespace std;

/*
* ����, ����, ��ȣ
* N = ���� * X + Y
* �� : X * 100 + Y
*/

int main()
{
	int T;
	int row, col;
	int Y, X, N;
	int number;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		number = 1;
		cin >> row >> col >> N;
		X = N / row+1;
		Y = N % row;
		if (Y == 0)
		{
			X--;
			Y = row;
		}
		cout << Y*100 + X << endl;
	}
}