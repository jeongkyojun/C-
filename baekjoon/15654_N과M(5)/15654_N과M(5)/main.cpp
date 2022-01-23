#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
* ������� �ʾ �ð��ʰ� ��
* printf �� scanf�� �ٲ���. �׷��� �ȴ�.
*/

// 1. ���� ���� v
// 2. ���� ���� ���� p
// 3. ��͵��� �־����� Ȯ���� b
// 4. ���� ���� �ε����� ǥ���� i
// 5. �迭�� �ִ� ũ�� M
// 6. �迭�� ���� ũ�� point
void N_M(vector<int>&v,vector<int>p, vector<bool> b,int i,int M, int point)
{
	p.push_back(v[i]);
	b[i] = true;
	if (point == M) // �ִ� ������ŭ �־����� ���
	{
		for (int j = 0; j < p.size(); j++)
		{
			cout << p[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (!b[j])
			{ 
				if (v[j] > v[i]) // ���簪�� ���ݺ��� Ŭ���
				{
					N_M(v, p, b, j, M, point + 1);
				}
			}
		}
	}
}
int main()
{
	vector<int> v,p;
	vector<bool> b;
	int N, M,num;
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		b.push_back(false);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		N_M(v, p, b, i, M, 1);
	}
}