#include<iostream>

using namespace std;

/*
* '축에 평행한 직사각형'
*/
int main()
{
	int x1, x2, x3,xr;
	int y1, y2, y3,yr;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	
	if (x1 == x2)
		xr = x3;
	else if (x2 == x3)
		xr = x1;
	else
		xr = x2;
	
	if (y1 == y2)
		yr = y3;
	else if (y2 == y3)
		yr = y1;
	else
		yr = y2;
	cout << xr << " " << yr << endl;
}