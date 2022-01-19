#include<iostream>

using namespace std;

int main()
{
	int i[100], num;
	i[0] = 0;
	i[1] = 1;
	i[2] = 1;
	cin >> num;
	for (int a = 3; a <= num; a++)
	{
		i[a] = i[a - 1] + i[a - 2];
	}
	cout << i[num]<<endl;
}