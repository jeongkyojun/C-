#include<iostream>
#include<cmath>
#define PI 3.14159265358979323846
using namespace std;

/*
* 유클리드 기하학
* Du = PI * (pow(x2-x1,2) + pow(y2-y1,2))
* 
* 택시 기하학
* (x1,y1) , (x2,y2) 간의 거리 D
* Dt = abs(x1-x2) + abs(y1-y2)
* 즉, 택시 기하학에서의 원은 마름모꼴 모양이다.
*/

int main()
{
	double uclid,taxi;
	//float 쓰면 틀린다. double을 쓰자!
	int n;
	cin >> n;
	uclid = n * n * PI;
	taxi = 2 * n * n; // 2n *2n / 2 이므로 n*n*2가 된다.
	printf("%.7f\n", uclid);
	printf("%.7f\n", taxi);
}