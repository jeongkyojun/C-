#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
* ios::sync_with_stdio(false);
* cin.tie(NULL);
* ��¹� �Է� ������ ���� ��� �� 2���� �� ����! �̰Ͷ����� �ð��ʰ� ���´�.
*/

class member
{
public:
	int number;
	string name;
	member()
	{
		number = 0;
		name = "";
	}
	member(int number, string name)
	{
		this->number = number;
		this->name=name;
	}

	int getnumber()
	{
		return number;
	}
	
	bool operator < (const member& members) const
	{
		return number < members.number;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<member> vec;
	int N, num;
	string name;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		getline(cin, name);
		vec.push_back(member(num, name));
	}
	stable_sort(vec.begin(),vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].number << vec[i].name << "\n";
	}
}


/*
class member
{
private:
	int number;
	vector<string> name;
public:
	member(int number, string name)
	{
		this->number = number;
		this->name.push_back(name);
	}
	void input(string name)
	{
		this->name.push_back(name);
	}
	void show()
	{
		for (int i = 0; i < name.size(); i++)
		{
			cout << number << " " << name[i]<<endl;
		}
	}
};

void Qsort(int vec[],int low, int high)
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
			Qsort(vec, low, j - 1);
			Qsort(vec, j + 1, high);
		}
}

int main()
{
	vector<member> membership;
	int num,N;
	string name;
	int vec[201], record[201],sort_vec[201];
	for (int i = 0; i < 201; i++)
	{
		vec[i] = 0;
		//record[i] = -1;
		//sort_vec[i] = 0;
	}
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		getline(cin, name);
		if (vec[num] == 0)//����ִ��� Ȯ��
		{
			vec[num] = 1;
			sort_vec[cnt] = num;
			record[num] = cnt++;
			membership.push_back(member(num, name));
			//��������� ���� �ִ´�, record�� sort_vec�� num���� �߰��Ѵ�.
		}
		else
		{
			membership[record[num]].input(name);
			//�������� ���� �ִ´�.(record[num]�� num�� �ִ� ������ ��ġ)
		}
	}
	// sort_vec���� �����ϴ� ���̸� �� �� �ִ�. 
	// cnt�� ���� �ٸ� ������ �����̴�. 
	// record�� ���̰� �ִ� ������ ��ġ�̴�.
	// vec�� �ش� ������ ȸ�� ���̴�.
	Qsort(sort_vec, 0, cnt - 1); // ���̸� �����Ѵ�.

	for (int i = 0; i < cnt; i++)
	{
		membership[record[sort_vec[i]]].show();
	}
}
*/
/*
* map�� ����ϴ� �ð��ʰ��� �ɸ���.
int main()
{
	vector<string> vec;
	map<int, vector<string> > maps;
	vector<map<int, vector<string> > > mats;
	map<int, vector<string> > ::iterator mapit;
	int N,num;
	string name;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		getline(cin, name);
		maps[num].push_back(name);
	}
	//sort(maps.begin(), maps.end());
	
	for (mapit = maps.begin(); mapit != maps.end(); ++mapit)
	{
		for (int i = 0; i < mapit->second.size(); i++)
		{
			cout<< mapit->first<<" "<<mapit->second[i]<<endl;
		}
	}
}
*/