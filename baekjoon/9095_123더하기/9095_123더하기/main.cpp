#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vec;

	int num,t;

	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);//1
	vec.push_back(2);//2

	//n = vec[n-1]

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> num;

		while (vec.size() <= num + 1)
		{
			vec.push_back(vec[vec.size() - 1] + vec[vec.size() - 2] + vec[vec.size() - 3]);
		}
		cout << vec[num + 1] << endl;
	}
}