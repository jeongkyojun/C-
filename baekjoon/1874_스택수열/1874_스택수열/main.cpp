#include<iostream>

using namespace std;

int main()
{
	// 맨 처음 a 가 나온경우, a 이전의 수는 모두 push를 선택한 것
	char chars[200001];
	int stacks[100001],top = 0,stack_top = 0;
	int n;
	int recent=0,recent_big=0,num;
	int isTrue = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (recent_big < num)
		{
			for (int i = recent_big; i < num; i++)
			{
				stacks[stack_top++] = i+1;
				chars[top++] = '+';
			}
			chars[top++] = '-';
			recent_big = num;
			recent = stacks[(--stack_top)-1];
		}
		else
		{
			if (recent == num)
			{
				chars[top++] = '-';
				recent = stacks[(--stack_top)-1];
			}
			else
			{
				isTrue = 0;
			}
		}
	}
	if (isTrue)
	{
		for (int i = 0; i < top; i++)
		{
			printf("%c\n", chars[i]);
		}
	}
	else
	{
		cout << "NO" << endl;
	}
}