#include<iostream>

using namespace std;

/*
* abcd ��� ������,
* abcd	= x + y + z + w + x*1000 + y*100 + z*10 +w
* �ִ� ���� : �ڸ��� * 9, �ּ� ���� = 1
* abcd - n�� ����������, n�� �Ǵ� ��찡 ����
*/

int main()
{
	int n,res=0;
	int num,cut=1,nums;
	int cnt = 1;
	cin >> n;
	//������ �ĺ� ���� ���ϱ� ( 9*cnt )
	while (n >= cut * 10)
	{
		cut *= 10;
		cnt ++;
	}
	cut = 1;
	for (int i = 9*cnt; i > 0; i--)
	{
		cut = 1;
		nums = 0;
		num = n - i;
		if (num < 0)
			continue;
		while(num>=cut*10)
			cut *= 10;
		while (cut > 0)
		{
			// �ĺ��� ������ ���ϱ�
			nums += num / cut;
			num = num%cut;
			cut /= 10;
		}
		if (i == nums)//�������� ��ġ�ϴ��� Ȯ��
		{
			res = n - i;
			break;
		}
	}
	cout << res<<endl;
}