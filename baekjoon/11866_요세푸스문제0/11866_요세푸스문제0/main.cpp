#include<iostream>

using namespace std;

int del(int &head,int queue[], int K,int &size);
void print(int queue[], int size);
int main()
{
	int queue[1001];
	int K, N, head=0, size=0,num;

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		queue[size++] = i;
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		cout << del(head, queue, K, size);
		if (i < N - 1)
			cout << ", ";
	}
	cout << ">" << endl;
}

int del(int &head, int queue[],int K,int &size)
{
	int p = (head + K - 1) % size;
	int res = queue[p];

	for (int i = p; i< size; i++)
	{
		queue[i] = queue[i + 1];
	}
	head = p;
	size--;
	return res;
}

void print(int queue[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << queue[i] << " ";
	}
	cout << endl;
}