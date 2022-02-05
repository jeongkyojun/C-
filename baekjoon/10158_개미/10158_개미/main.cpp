#include<iostream>

using namespace std;

int main()
{
	int dx = 1;
	int dy = 1;
	int x, y,W,H,num;
	cin >> W >> H;
	cin >> x>> y;
	cin >> num;
	x += num;
	y += num;
	if (x / W % 2 == 0)
		x = x % W;
	else
		x = W - (x % W);
	if (y / H % 2 == 0)
		y = y % H;
	else
		y = H - (y % H);
	cout << x << " " << y << endl;
}