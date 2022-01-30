#include<iostream>
#include<vector>

using namespace std;
struct N
{
	long num;
	int res;
};
int main()
{
	vector<int> B;
	N n;
	N A[100000];
	bool isFind = false;
	int head = 0;
	int tail = 0;
	int numA, numB,res = -1;
	cin >> numA >> numB;
	A[tail].num = numA;
	A[tail++].res = 1;
	while (head <= tail)
	{
		n = A[head++];
		if (n.num * 2 == numB || n.num*10 + 1 == numB)
		{
			res = n.res + 1;
			break;
		}
		if (n.num * 2 < numB && n.num*2>0)
		{
			isFind = false;
			for (int i = 0; i < B.size(); i++)
			{
				if (B[i] == n.num * 2)
				{
					isFind = true;
					break;
				}
			}
			if (!isFind)
			{
				A[tail].num = n.num * 2;
				A[tail++].res = n.res + 1;
				B.push_back(n.num * 2);
			}
		}
		if (n.num*10 + 1 < numB && n.num *10 + 1> 0)
		{
			isFind = false;
			for (int i = 0; i < B.size(); i++)
			{
				if (B[i] == n.num*10 +1)
				{
					isFind = true;
					break;
				}
			}
			if (!isFind)
			{
				cout << "input " << n.num * 10 + 1 << endl;
				A[tail].num = n.num*10 + 1;
				A[tail++].res = n.res + 1;
				B.push_back(n.num*10 + 1);
			}
		}
	}
	cout << res<<endl;
}