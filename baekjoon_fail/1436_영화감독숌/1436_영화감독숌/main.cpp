#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[10];
	int b[10];
	int num,setnum;
	int result;
	/*
	* F(3) = 1, T(3) = 1
	* F(4) = 1*8 + 10 = F(3)*8 + 10 ,T(4) = 10(6660 ~ 6669)
	* F(5) = F(4)*8 + 60666,66600~66699 -> T(3) + 100
	* F(6) = F(5)*8 + 600666 , 606660~606669 , 60666 & 666000~666999 -> T(3)+T(4)+ 1000
	* F(n) = F(n-1)*8 + T(n-2)~T(0) + 10^n-3;
	* T(n) = T(n-1)~T(0) + 10^n-3
	*/

	for (int i = 0; i < 3; i++)
	{
		a[i] = 0;
		b[i] = 0;
	}
	// b[i] = for(int j=0;j<i-1;j++)b[j] + 10^i-3
	// a[i] = a[i-1]*8 + b[i];
	a[3] = 1;
	b[3] = 1;

	for (int i = 4; i < 10; i++)
	{
		b[i] = 0;
		for (int j = 0; j < i - 1; j++)
			b[i] += b[j];
		b[i] += pow(10, i - 3);

		a[i] = a[i - 1] * 9 + b[i];
	}

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;

	cin >> num;
	for (int i = 0; i < 10; i++)
	{
		if (num < a[i])
		{
			setnum = i;
			break;
		}
	}
	cout << "n의 범위 : " << setnum << endl;

	int maxnum = a[setnum];
	cout << "maxnum : " << maxnum << endl;
	bool goTonext = false,findout = false;
	while (maxnum > num)
	{
		goTonext = false;
		
		// 자리수 구하기 1 (0~6사이 범위)
		for (int i = 0; i < 6; i++)
		{
			if (maxnum -a[setnum-1] < num)
			{
				result += pow(10, setnum) * i;
				goTonext = true;
				break;
			}
			maxnum -= a[setnum - 1];
		}
		if (goTonext)
		{
			setnum--;
			continue;
		}
		// 자리수 구하기 2 (6 범위)
		if (maxnum - b[setnum] < num)
		{
			// 이 구간에 들어오면 완전하게 찾아내고 끝낸다.
			findout = true;
			//(666)
			//(6660 6661 6662 6663...6669)
			//(60666) (66600 66601 66602 66603 ... 66699)
			//(600666) (606660 ... 606669) (666000 ... 666999)
			// 먼저 b[n-2] 까지를 확인하고, 10^n-3 범위내로 들어간다.
			while (maxnum > num)
			{
				goTonext = false;
				for (int i = 0; i < setnum - 2; i++)
				{
					if (maxnum - b[setnum] < num)
					{
						goTonext = true;
					}
				}
			}
		}
		
		if (goTonext)
			break;

		// 자리수 구하기 3 (7~9사이 범위)
		for (int i = 7; i < 10; i++)
		{
			if (maxnum - a[setnum - 1] < num)
			{
				result += pow(10, setnum) * i;
				break;
			}
			maxnum -= a[setnum - 1];
		}
	}
	if (!findout)
		result += 666;
	cout << result << endl;
}