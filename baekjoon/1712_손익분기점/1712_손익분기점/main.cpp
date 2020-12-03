#include<iostream>
using namespace std;

/*
* 노트북 제조 및 판매
* 매년 임대료, 재산세, 보험료 급여 등 A의 고정비용
* 노트북 한대 당 B의 가변 비용 듦
* -> A + (n*B)
* 
* 노트북 가격 C로 책정
* 
* n*C = A+(n*B) 인 n의 값이 있을 때, n을 넘는 자연수의 최솟값은?
* n*(C-B) = A
*/

int main()
{
	int A, B;
	int C;
	int num;

	cin >> A >> B>>C;
	
	if (C<=B)
		num = -1;
	else
		num = A / (C - B) + 1;

	cout << num;
}