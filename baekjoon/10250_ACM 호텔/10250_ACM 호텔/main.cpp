#include<iostream>

using namespace std;

/*
* 세로, 가로, 번호
* N = 세로 * X + Y
* 답 : X * 100 + Y
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