#include<iostream>
using namespace std;

/*
* ��Ʈ�� ���� �� �Ǹ�
* �ų� �Ӵ��, ��꼼, ����� �޿� �� A�� �������
* ��Ʈ�� �Ѵ� �� B�� ���� ��� ��
* -> A + (n*B)
* 
* ��Ʈ�� ���� C�� å��
* 
* n*C = A+(n*B) �� n�� ���� ���� ��, n�� �Ѵ� �ڿ����� �ּڰ���?
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