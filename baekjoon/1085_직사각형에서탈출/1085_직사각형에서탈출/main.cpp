#include<iostream>

using namespace std;

/*
*  w-x, h-y, x, y �� ���� ���� ���� ����
*/

int min(int x, int y)
{
	if (x < y)
		return x;
	return y;
}
int main()
{
	int w, h, x, y;
	cin >> x >> y >> w >> h;
	cout << min(min(w - x, h - y),min(x,y))<<endl;
}