#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	// �����ϴ°ͺ��� mapping�� �� �����Ͱ��ٰ� �Ǵ�
	int N, M,num;
	map<int, int> many;
	vector<int> nums;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		many[num]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		nums.push_back(num);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		cout << many[nums[i]] << " ";
	}
	cout << endl;
}