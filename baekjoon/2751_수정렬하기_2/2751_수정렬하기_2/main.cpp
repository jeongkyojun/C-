#include<iostream>
#include<vector>
using namespace std;

/*
* I hate mergesort
*/
void merge(int vec[], int low, int high, int mid)
{
	int vecs[100000];
	int i = low, j = mid+1,k = low;
	while (i <= mid && j <= high)
	{
		
		if (vec[i] < vec[j])
		{
			vecs[k++] = vec[i++];
		}
		else
		{
			vecs[k++] = vec[j++];
		}
	}
	if (i <= mid)
	{
		for (int x = i; x <= mid; x++)
		{
			vecs[k++] = vec[x];
		}
	}
	else
	{
		for (int x = j; x <= high; x++)
		{
			vecs[k++] = vec[x];
		}
	}
	
	for (int a = low; a <= high;a++)
		vec[a] = vecs[a];
}

void mergesort(int vec[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergesort(vec, low, mid);
		mergesort(vec, mid + 1, high);
		merge(vec, low, high, mid);
	}
}


int main()
{
	int N, num;
	int vec[100000];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec[i]=num;
	}
	mergesort(vec, 0, N-1);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", vec[i]);
	}
}