#include<iostream>
#include<vector>

using namespace std;

/*
* 무게에서 가질 수 있는 최대의 가치를 표시한다.
* 4 7
* 6 13
* 4 8
* 3 6
* 5 12
* 
* 1. vec[4] = 7
* 
* 2. vec[4] = 7 vec[6] = 13 vec[10] = 20
* 
* 3. vec[4] = 8 vec[6] = 13 vec[10] = 21 vec[14] = 28
* ....
* 이후, 무게 W내에서 최대 가치를 고르면 된다. 
*/

class item
{
private:
	int value;
	int weight;
public:
	item(){}
	item(int value, int weight)
	{
		this->value = value;
		this->weight = weight;
	}

	int getValue() { return value; }
	int getWeight() { return weight; }
};


int main()
{
	int N,val,wei,W;
	vector<item> items;
	vector<int> vec,vec2;
	cin >> N >> W;
	for (int i = 0; i < N; i++)
	{
		cin >> wei >> val;
		items.push_back(item(val, wei));
	}

	for (int i = 0; i <= W; i++)
	{
		vec.push_back(0);
		vec2.push_back(0);
	}

	int MaxW = 0,result = 0;

	for (int i = 0; i < items.size(); i++)
	{
		MaxW += items[i].getWeight();
		if (items[i].getWeight()<=W && vec[items[i].getWeight()] < items[i].getValue()) // 무게가 W를 넘지 않고, 해당 무게의 최대 가치보다 새로 제시된 가치가 더 큰 경우 
		{
			vec2[items[i].getWeight()] = items[i].getValue(); // vec2의 해당 무게에 해당 가치를 넣는다.
			if (items[i].getValue() > result)//최댓값인 경우 갱신한다.
				result = items[i].getValue();
		}
		for (int j = 0; j <= MaxW; j++) //최대 무게 비교
		{
			if (j > W)
				break;
			if (vec[j] != 0 && j+items[i].getWeight()<=W) // 무게가 존재하고, 무게에 추가했을때 최대 무게를 넘지 않는다면,
			{
				if (vec[j + items[i].getWeight()] < vec[j] + items[i].getValue())// 가치를 비교하여
				{
					vec2[j + items[i].getWeight()] = vec[j] + items[i].getValue();//큰 값을 넣는다.
					
					if (result < vec[j] + items[i].getValue())
					{
						result = vec[j] + items[i].getValue();
					}
				}
			}
		}

		vec = vec2;
	}
	cout << result << endl;
}