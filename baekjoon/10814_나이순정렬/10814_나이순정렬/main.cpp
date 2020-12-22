#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
* ios::sync_with_stdio(false);
* cin.tie(NULL);
* 출력및 입력 개수가 많을 경우 위 2개는 꼭 넣자! 이것때문에 시간초과 나온다.
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
		if (vec[num] == 0)//비어있는지 확인
		{
			vec[num] = 1;
			sort_vec[cnt] = num;
			record[num] = cnt++;
			membership.push_back(member(num, name));
			//비어있으면 값을 넣는다, record와 sort_vec에 num값을 추가한다.
		}
		else
		{
			membership[record[num]].input(name);
			//차있으면 값만 넣는다.(record[num]은 num이 있는 벡터의 위치)
		}
	}
	// sort_vec에는 존재하는 나이를 알 수 있다. 
	// cnt는 각자 다른 나이의 개수이다. 
	// record는 나이가 있는 벡터의 위치이다.
	// vec은 해당 나이의 회원 수이다.
	Qsort(sort_vec, 0, cnt - 1); // 나이를 정렬한다.

	for (int i = 0; i < cnt; i++)
	{
		membership[record[sort_vec[i]]].show();
	}
}
*/
/*
* map을 사용하니 시간초과가 걸린다.
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