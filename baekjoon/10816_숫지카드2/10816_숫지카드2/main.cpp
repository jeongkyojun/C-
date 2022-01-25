#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
	// 정렬하는것보다 mapping이 더 나을것같다고 판단
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