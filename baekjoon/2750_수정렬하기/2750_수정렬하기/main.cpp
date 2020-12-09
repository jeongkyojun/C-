#include<iostream>
#include<vector>
using namespace std;

void quicksort(vector<int>& vec,int low, int high)
{
	int i, j = low;
	int k = low;
	int tmp;
	if (low < high)
	{
		for (i = low + 1; i <= high; i++)
		{
			if (vec[k] > vec[i])
			{
				tmp = vec[++j];
				vec[j] = vec[i];
				vec[i] = tmp;
			}
		}
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << " ("<<j<<")"<<endl;
		tmp = vec[j];
		vec[j] = vec[k];
		vec[k] = tmp;
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl<<endl;
		quicksort(vec, low, j - 1);
		quicksort(vec, j + 1, high);
	}
}


int main()
{
	int N,num;
	vector<int> vec;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		vec.push_back(num);
	}
	quicksort(vec, 0, vec.size() - 1);
	for (int i = 0; i < N; i++)
	{
		cout<<vec[i]<<" ";
	}
}