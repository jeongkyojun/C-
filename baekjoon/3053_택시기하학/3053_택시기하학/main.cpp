#include<iostream>
#include<cmath>
#define PI 3.14159265358979323846
using namespace std;

/*
* ��Ŭ���� ������
* Du = PI * (pow(x2-x1,2) + pow(y2-y1,2))
* 
* �ý� ������
* (x1,y1) , (x2,y2) ���� �Ÿ� D
* Dt = abs(x1-x2) + abs(y1-y2)
* ��, �ý� �����п����� ���� ������� ����̴�.
*/

int main()
{
	double uclid,taxi;
	//float ���� Ʋ����. double�� ����!
	int n;
	cin >> n;
	uclid = n * n * PI;
	taxi = 2 * n * n; // 2n *2n / 2 �̹Ƿ� n*n*2�� �ȴ�.
	printf("%.7f\n", uclid);
	printf("%.7f\n", taxi);
}