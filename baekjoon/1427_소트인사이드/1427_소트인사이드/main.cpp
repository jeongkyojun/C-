#include<iostream>
#include<string>

using namespace std;


void quicksort(string &str, int low, int high)
{
	int j = low,k = low;
	char tmp;
	if (low < high)
	{
		for (int i = low; i <= high; i++)
		{
			if (str[k] < str[i])
			{
				tmp = str[i];
				str[i] = str[++j];
				str[j] = tmp;
			}
		}
		tmp = str[k];
		str[k] = str[j];
		str[j] = tmp;
		quicksort(str, low, j - 1);
		quicksort(str, j + 1, high);
	}
}

int main()
{
	string str;

	cin >> str;
	quicksort(str, 0, str.size()-1);
	cout << str << endl;
}