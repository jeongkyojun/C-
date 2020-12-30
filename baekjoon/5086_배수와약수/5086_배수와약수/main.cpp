#include<iostream>

using namespace std;

int main()
{
	int A, B, num;

	while (true)
	{
		cin >> A>>B;
		if (A==B)
			break;
		if (A < B && B % A == 0)
			cout << "factor" << endl;
		else if (A > B && A % B == 0)
			cout << "multiple" << endl;
		else
			cout << "neither" << endl;
	}
}