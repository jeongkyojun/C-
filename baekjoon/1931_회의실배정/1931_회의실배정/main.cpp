#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> times;
	vector<int> score_double;
	int start, end,T,sp = 100001,res=0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{

		cin >> start >> end;
		if (times.size() <= end)
		{
			for (int j = times.size(); j <= end; j++)
			{
				times.push_back(-1);
				score_double.push_back(0);
			}
		}
		//������ �ð��� ������ ���۽ð��� ū�͸� �����.
		if (end == start)
			score_double[end] ++;
	
		// 1. ������ �ð��� �����ϴ� �ð��� ������ ��� A��� �Ѵ�.
		// 2. times[end] =-1�̸� ������ �����. A�϶��� �����.
		if(times[end]==-1)
			times[end] = start;
		else if (start != end)
		{
			// 3.������Ҷ� ����� A�ΰ��� ������ �����.
			if (times[end]==end)
			{
				times[end] = start;
			}
			// 4. �� �ܿ� �Ϲ����� ������ �Ѵ�.
			else if (times[end] < start)
			{
				times[end] = start;
			}
		}
		//������ ����
		if (sp > end)
			sp = end;
	}
#pragma region MyRegion
	for (int i = 0; i < times.size(); i++)
	{
		cout << times[i] << " ";
	}
	cout << endl;
#pragma endregion
	start = 0;
	for (int i = sp; i < times.size(); i++)
	{
		//�ش� ũ�⿡ ���� ������ pass
		if (times[i] == -1)
			continue;
		else
		{
			// �������� �ߺ��Ǵ��� Ȯ���Ѵ�.
			if (times[i] < start)
				continue;
			else
			{
				res++;
				start = i;
				// ���۽ð��� ���ð��� ������ ��찡 �����ϸ�, �ߺ��� ��ŭ ���� �ִ´�.
				if (score_double[i])
					res+=score_double[i];
				if (times[i] == i)
					res--;
			}
		}
	}
	cout << res << endl;
}
