#include<iostream>

using namespace std;

/*
* abcd 라고 했을때,
* abcd	= x + y + z + w + x*1000 + y*100 + z*10 +w
* 최대 숫자 : 자리수 * 9, 최소 숫자 = 1
* abcd - n을 분해했을때, n이 되는 경우가 정답
*/

int main()
{
	int n,res=0;
	int num,cut=1,nums;
	int cnt = 1;
	cin >> n;
	//생성자 후보 개수 구하기 ( 9*cnt )
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
			// 후보의 분해합 구하기
			nums += num / cut;
			num = num%cut;
			cut /= 10;
		}
		if (i == nums)//분해합이 일치하는지 확인
		{
			res = n - i;
			break;
		}
	}
	cout << res<<endl;
}