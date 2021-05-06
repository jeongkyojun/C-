#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,num;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		a.push_back(num);
	}
	cout << sum(a) << endl;
}

long long sum(std::vector<int>& a)
{
	long long sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		sum += a[i];
	}
	return sum;
}
