#include<iostream>
#include<cmath>
using namespace std;


int boundary_6(int n)
{
	//3 -> 0
	//4 -> 1 (10)
	return pow(10, n);
}

int boundary(int n)
{
	if (n < 3)
		return 0;
	if (n == 3)
		return 1;
	return 9*boundary(n-1)+9*boundary(n-2)+boundary_6(n-3);
}
void getnum_6(int num, int n, int& res);
void getnum(int num, int& res);


int main()
{
	int n;
	int res, num;
	cin >> n;
	res = 0;
	getnum(n, res);
	cout << "answer : "<<res << endl;
}

void getnum_6(int num, int n, int& res)
{
	int body;
	cout << "getnum_6 num : "<<num<< endl;
	if (num == 1)
		res += 666;
	n = n - 2;
	body = 9*boundary(n)+boundary_6(n-1);
	cout << "body : " << body << " ,  boundary(n) : " << boundary(n) << endl;
	if (num > 1)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "i : " << 9 - i << endl;
			if (i == 3)
			{
				cout << "6일때의 경계 : " << (9 * boundary(n - 1) + boundary_6(n - 2)) << endl;
				if (body - (boundary_6(n - 1)) < num)
				{
					res += boundary_6(n) * (9 - i);
					res += boundary_6(n - 1) * (9 - i);
					num -= boundary(n) * (9 - i);
					cout << "num_6를 뺀 값 : " << num << endl;
					res += num-1;
					cout << "res : " << res << " & num : " << num << "(" << n << ")" << endl;
					return;
				}
				else
				{
					body -= boundary_6(n - 1);
				}
			}
			else
			{
				cout << "body - boundary(n)" << body - boundary(n) <<endl;
				if (body - boundary(n) < num)
				{
					res += boundary_6(n) * (9 - i);
					cout << "+" << boundary_6(n) * (9 - i) << endl;
					num -= boundary(n) * (9 - i);
					if (i < 3)
					{
						num += boundary(n);
						num -= boundary_6(n-1);
					}

					cout << "res : " << res << " & num : " << num << endl;
					getnum(num, res);
				}
				else
				{
					body -= boundary(n);
				}
			}
		}
	}
}


void getnum(int num, int& res)
{
	cout << "getnum" << endl;
	int n = 3;
	int body = 0;
	if (num == 1)
		res += 666;
	if (num > 1)
	{
		while (num > boundary(n))
		{
			//이를 통해 자리수 cut을 구한다.
			n++;
		}
		cout << num << " , " << boundary(n) << endl;
		// 이제는 num<=boundary(n)이 성립
		body = boundary(n);
		for (int i = 0; i < 10; i++)
		{
			cout << "body : " << body<<" & i : "<<9-i << endl;
			if (i == 3)
			{
				if (body - (9 * boundary(n - 2) + boundary_6(n-3)) < num)
				{
					res += boundary_6(n-1) * (9 - i);	// res에 값 더하기
					cout << num<<endl;
					//num 에서 앞자리 빼기 -> 19?
					num -= boundary(n - 1)*(9-i);
					cout << "res : " << res << " & num : " << num << "(" << n << ")" << endl;
					getnum_6(num, n,res);
					return;
				}
				else
				{
					body -= (9 * boundary(n - 2) + boundary_6(n-3));
				}
			}
			else
			{
				if (body - boundary(n - 1) < num)
				{
					res += boundary_6(n-1) * (9 - i);
					num -= boundary(n - 1) * (9 - i);
					cout << "num - "<<boundary(n - 1) * (9 - i) << endl;
					if (i < 3)
					{
						num += boundary(n - 1);
						num -= (9 * boundary(n - 2) + boundary_6(n-3));
					}
					cout << "res : " << res << " & num : " << num << endl;
					getnum(num, res);
				}
				else
				{
					body -= boundary(n - 1);
				}
			}
		}
	}
}
