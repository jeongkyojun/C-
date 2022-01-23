#include<iostream>
#include<vector>
using namespace std;
long long func(int res, vector<long long>& vec,vector<long long>&v_r,vector<vector<bool> >&m_b)
{
	int max = 0;
	for (int i = 1; i <vec.size(); i++)
	{
		if (m_b[i][res]) // i->res 테크가 존재한다면
		{
			if (m_b[0][i])
			{
				if (max < v_r[i]) // 새로운 테크에서 가장 큰 값 구하기
					max = v_r[i];
			}
			else
			{
				if (max < func(i, vec, v_r, m_b)) // 새로운 테크에서 가장 큰 값 구하기
					max = func(i, vec, v_r, m_b);
			}
		}
	}
	if (v_r[res] < vec[res] + max) // 현재값과 새로운 테크시간 비교
		v_r[res] = vec[res] + max;
	m_b[0][res] = true;// 진행한 위치 마킹
	return v_r[res]; // 테크가 존재하지 않으면 제값을 보낸다.
}
int main()
{
	int T,B,N,X,Y;
	int num,res;
	vector <long long> v,v_r;
	vector<bool> v_b;
	vector<vector<bool> >m_b;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		v_r.clear();
		m_b.clear();
		v.clear();
		v_b.clear();
		cin >> B; // 건물의 개수
		cin >> N; // 건설순서 규칙의 개수
		for (int i = 0; i <= B; i++)
		{
			v_b.push_back(false);
			v.push_back(-1);
			v_r.push_back(-1);
		}
		m_b.push_back(v_b);
		for (int i = 0; i < B; i++) // 값 입력
		{
			m_b.push_back(v_b);
			cin >> num;
			v[i + 1] = num;
			v_r[i + 1] = num;
		}

		// X - Y 테크 기록
		for (int i = 0; i < N; i++)
		{
			cin >> X;
			cin >> Y;
			m_b[X][Y] = true;
		}
		cin >> res;
		cout<<func(res,v,v_r,m_b)<<endl;
	}
}