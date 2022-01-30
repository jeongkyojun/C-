#include<iostream>
#include<vector>
using namespace std;

long long int MUL(int A, int B, int C)
{
	int mid = B / 2;
	if (B == 1)
		return A % C;
	if(B%2==1)
		return MUL(A, mid, C)%C * MUL(A, mid+1, C)%C;
	return MUL(A, mid, C)%C * MUL(A, mid, C)%C;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << MUL(A, B, C)<<endl;
}