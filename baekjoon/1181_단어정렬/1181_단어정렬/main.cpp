#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<string> str;
	vector <vector<string> >mat;
	string sentence;
	int N, len;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> sentence;
		len = sentence.size();
		if (len > mat.size())
		{
			for (int x = mat.size(); x < len; x++)
			{
				mat.push_back(str);
			}
		}
		// 중복된 단어가 있는지 검색, 제외한다.
		vector<string>::iterator it = find(mat[len - 1].begin(), mat[len - 1].end(), sentence);
		if (it == mat[len - 1].end())
			mat[len - 1].push_back(sentence);
	}
	for (int i = 0; i < mat.size(); i++)
	{
		sort(mat[i].begin(), mat[i].end());
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat[i][j] << endl;
		}
	}
}