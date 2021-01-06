#include<iostream>
#include<vector>

using namespace std;

/*
* ���Կ��� ���� �� �ִ� �ִ��� ��ġ�� ǥ���Ѵ�.
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
* ����, ���� W������ �ִ� ��ġ�� ���� �ȴ�. 
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
		if (items[i].getWeight()<=W && vec[items[i].getWeight()] < items[i].getValue()) // ���԰� W�� ���� �ʰ�, �ش� ������ �ִ� ��ġ���� ���� ���õ� ��ġ�� �� ū ��� 
		{
			vec2[items[i].getWeight()] = items[i].getValue(); // vec2�� �ش� ���Կ� �ش� ��ġ�� �ִ´�.
			if (items[i].getValue() > result)//�ִ��� ��� �����Ѵ�.
				result = items[i].getValue();
		}
		for (int j = 0; j <= MaxW; j++) //�ִ� ���� ��
		{
			if (j > W)
				break;
			if (vec[j] != 0 && j+items[i].getWeight()<=W) // ���԰� �����ϰ�, ���Կ� �߰������� �ִ� ���Ը� ���� �ʴ´ٸ�,
			{
				if (vec[j + items[i].getWeight()] < vec[j] + items[i].getValue())// ��ġ�� ���Ͽ�
				{
					vec2[j + items[i].getWeight()] = vec[j] + items[i].getValue();//ū ���� �ִ´�.
					
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