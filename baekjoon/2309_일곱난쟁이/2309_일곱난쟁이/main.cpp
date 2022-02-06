#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void tracking(vector<int>gnome, vector<int>lst, int num, int W,int MaxW,int gnome_number, bool &stop)
{
	if (stop)
		return;
	if (gnome_number == 7)
	{
		if (W == 100)
		{
			stop = true;
			for (int i = 0; i < lst.size(); i++)
			{
				cout << lst[i] << endl;
			}
		}
	}
	else
	{
		if (num<gnome.size() && MaxW+W>=100)
		{
			tracking(gnome, lst, num + 1, W, MaxW - gnome[num], gnome_number, stop);
			lst.push_back(gnome[num]);
			tracking(gnome, lst, num + 1, W+gnome[num], MaxW - gnome[num], gnome_number + 1, stop);
		}
	}
}
int main()
{
	vector<int> lst;
	int size, max_size =0;
	vector<int> gnome;
	for (int i = 0; i < 9; i++)
	{
		cin >> size;
		max_size += size;
		gnome.push_back(size);
	}
	bool stop = false;
	sort(gnome.begin(), gnome.end());
	tracking(gnome, lst, 0, 0,max_size,0,stop);
}