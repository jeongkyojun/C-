#include<iostream>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
int bfs(vector<int> v, map<int, int> w, int M,int &layer)
{
	vector<int> v2;
	map<int, int>w2;
	bool isResult = false;
	int min[100001];
	int r = 0;

	// ó������ ������ġ�� 1 ��ȯ
	if (v[0] == M)
		return 1;
	
	// �ּڰ� �ʱ�ȭ
	for (int i = 0; i < 100001; i++)
	{
		min[i] = 200000;
	}
	min[v[0]] = 0;
	while(true)
	{
		layer++; // �ܰ� ����
		cout << "######## layer : " << layer << endl;
		// �ܰ躰�� v�� ���Ҹ� ������ Ȯ��
		for (int i = 0; i < v.size(); i++)
		{
			cout << "open " << v[i] << endl;
			if (v[i] + 1 == M || v[i] - 1 == M || v[i] * 2 == M)
			{
				isResult = true; // ��� ������ ǥ��
				r += w[v[i]]; // �ߺ��� ����
			}

			if (!isResult)
			{
				if (v[i] + 1 >= 0 && v[i] + 1 <= 100000)
				{
					if (min[v[i] + 1] > layer)
					{
						min[v[i] + 1] = layer;
						if (w2[v[i] + 1] == 0)
							v2.push_back(v[i] + 1);
						w2[v[i] + 1] += w[v[i]];
					}
				}
				if (v[i] - 1 >= 0 && v[i] - 1 <= 100000)
				{
					if (min[v[i] - 1] > layer)
					{
						min[v[i] - 1] = layer;
						if (w2[v[i] - 1] == 0)
							v2.push_back(v[i] - 1);
						w2[v[i] - 1] += w[v[i]];
					}
				}
				if (v[i]*2 >= 0 && v[i]*2 <= 100000)
				{
					if (min[v[i]*2] > layer)
					{
						min[v[i]*2] = layer;
						if (w2[v[i]*2] == 0)
							v2.push_back(v[i]*2);
						w2[v[i]*2] += w[v[i]];
					}
				}
			}
		}

		if (isResult)
			break; // ����� ������ �ٷ� ����

		// ������ �ӽð��� �ű�� �ʱ�ȭ
		w = w2;
		w2.clear();
		v = v2;
		v2.clear();
	}
	return r;
}
int main()
{
	int M, N;
	int layer = 0;
	vector<int>v;
	map<int, int>w;
	cin >> N >> M;
	v.push_back(N);
	w[N]++;
	int res = bfs(v, w, M, layer);
	cout << layer << endl;
	cout << res << endl;
}