#include<iostream>
#include<string>

using namespace std;

void quicksort(int vec[], int low, int high)
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
		tmp = vec[j];
		vec[j] = vec[k];
		vec[k] = tmp;
		quicksort(vec, low, j - 1);
		quicksort(vec, j + 1, high);
	}
}

void merge(int vec[], int low, int high, int mid)
{
	int i = low, j = mid + 1, k = low;
	int vecs[1000001];
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
	for (int a = low; a <= high; a++)
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

/*
//#A
int main()
{

	int T;
	cin >> T;
	int num,n;
	int arr[301];
	for (int test = 0; test < T; test++)
	{
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			cin >> n;
			arr[i] = n;
		}
		int a = 1, b = num;
		while (a <= b)
		{
			cout << arr[a++]<<" ";
			if(a<=b)
				cout << arr[b--] << " ";
		}
		cout << endl;
	}
}
*/
/*
//B
int main()
{
	string str;
	string str2 = "2020";
	int T, N;
	bool res;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> N;
		getchar();
		getline(cin, str,'\n');
		int a = 0, b = 3;
		for (int i = 0; i < 4; i++)
		{
			if (str[i] == str2[a])
			{
				a++;
			}
			else
				break;
		}
		res = true;
		for (int i = str.size()-1; i >= str.size()-(4-a); i--)
		{
			if (str[i] != str2[b--])
			{
				res = false;
				break;
			}
		}
		if (res)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
*/

/*
//C
int main()
{
	int T, N;
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> N;
		int x = 0,cnt=0;
		if (N > 45)
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 9; i >= 1; i--)
		{
			if (N >= i)
			{
				N -= i;
				int tmp = i;
				for (int j = 0; j < cnt; j++)
				{
					tmp *= 10;
				}
				x += tmp;
				cnt++;
			}
		}
		cout << x << endl;
	}
}
*/