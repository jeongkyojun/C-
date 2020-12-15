#include<iostream>
using namespace std;

/*
* -4000 ~ 4000 -> 0 ~ 8000
* Æò±Õ
* Áß¾Ó°ª
* ÃÖºó°ª
* ¹üÀ§
*/

int Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
int Max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int main()
{
	int num[8001],arr[8001];
	for (int i = 0; i <= 8000; i++)
	{
		num[i] = 0;
	}

	int avg,mid, mode, range;
	double average;
	int sum = 0,arr_line = 0;

	int min = 8001, max = -8001;
	int fre = 0,set = 0;

	int N, number;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		// ÃÖ´ñ°ª, ÃÖ¼Ú°ª, ÃÑÇÕ
		cin >> number;
		sum += number;
		num[number+4000]++;
		if (number < min)
			min = number;
		if (number > max)
			max = number;	
	}
	for (int i = 0; i <= 8000; i++)
	{
		for (int j = 0; j < num[i]; j++)
		{
			arr_line++;
			if (arr_line == N / 2 + 1)
				mid = i-4000;
		}
		if (num[i]!=0)
		{
			if (num[i] > fre)
			{
				mode = i-4000;
				fre = num[i];
				set = 0;
			}
			else if (num[i] == fre)
			{
				if (set < 1)
				{
					mode = Max(i-4000, mode);
					set++;
				}
			}
		}
	}
	cout << "sum : " << sum << endl;
	cout << endl;
	
	average = (double)sum / (double)N;
	avg = average;
	cout << "sub : " << average<<" - "<<avg << endl;
	if (average >= 0 && average - avg >= 0.5)
		avg++;
	else if (average < 0 && average - avg <= -0.5)
		avg--;
	range = max - min;
	cout << endl;
	printf("%d\n%d\n%d\n%d", avg, mid, mode, range);
}