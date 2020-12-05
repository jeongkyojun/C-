#include<iostream>
#include<cmath>
using namespace std;

/*
* 원 a (조규현) 과 원 b (백승환)가 만나는 점의 개수를 구해라.
* 
* 1. 두 점이 접촉하고 반지름 길이가 같은 경우
*	-> 무한히 많으므로 -1 출력
* 2. 큰 원의 반지름 > 작은원의 반지름 + 두 원의 중심간의 거리
*	-> 큰 원 안에 작은원이 있게 되므로 0
* 3. 두 원의 반지름의 합 < 두 원의 중심간 거리
*	-> 만날수가 없으므로 0
* 4. 두 원의 거리 = 두 원의 반지름의 합
*	-> 1
* 5. 큰 원의 반지름 = 작은원의 반지름 + 두 원의 중심간 거리
*	-> 1
* 그 외 = 2
*/

int main()
{
	int x1, x2, y1, y2, r1, r2, a, b, num;
	double r3;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		a = x1 - x2;
		b = y1 - y2;
		r3 = sqrt(pow(a, 2) + pow(b, 2)); // r3 : 두 원의 중심간 거리
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1";
		else
		{
			if (r1 + r2 < r3 || abs(r1 - r2) > r3)
			{
				cout << "0";
			}
			else if (r1 + r2 == r3 || abs(r1 - r2) == r3)
			{
				cout << "1";
			}
			else
				cout << "2";
		}
		cout << endl;
	}
	return 0;
}