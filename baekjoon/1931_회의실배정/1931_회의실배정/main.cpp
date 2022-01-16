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
		//끝나는 시간이 같으면 시작시간이 큰것만 남긴다.
		if (end == start)
			score_double[end] ++;
	
		// 1. 끝나는 시간과 시작하는 시간이 동일한 경우 A라고 한다.
		// 2. times[end] =-1이면 무조건 덮어쓴다. A일때도 덮어쓴다.
		if(times[end]==-1)
			times[end] = start;
		else if (start != end)
		{
			// 3.덮어쓰려할때 대상이 A인경우면 무조건 덮어쓴다.
			if (times[end]==end)
			{
				times[end] = start;
			}
			// 4. 그 외엔 일반적인 방법대로 한다.
			else if (times[end] < start)
			{
				times[end] = start;
			}
		}
		//시작점 설정
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
		//해당 크기에 값이 없으면 pass
		if (times[i] == -1)
			continue;
		else
		{
			// 시작점이 중복되는지 확인한다.
			if (times[i] < start)
				continue;
			else
			{
				res++;
				start = i;
				// 시작시간과 끝시간이 동일한 경우가 존재하면, 중복된 만큼 값을 넣는다.
				if (score_double[i])
					res+=score_double[i];
				if (times[i] == i)
					res--;
			}
		}
	}
	cout << res << endl;
}
