#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	vector<int> swt;
	cin >> T;
	swt.push_back(-1);
	int n;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		swt.push_back(n);
	}

	int std_num;
	cin >> std_num;
	for (int i = 0; i < std_num; i++) {
		int gender;
		int num;
		cin >> gender;
		cin >> num;
		if (gender == 1) {
			// �����ΰ��
			for (int j = num; j <= T; j += num) {
				swt[j] = (swt[j] + 1) % 2;
			}
		}
		else {
			// �����ΰ��
			for (int j = 1; j <= T; j++) { // n+i �� n-i�� ��, ������ �ٲ۴�.
				// ���� �߻��� break
				if (num - j <= 0 || num + j > T) // ������ ����� �����Ѵ�.
					break;
				// ��Ī�Ǵ°�� ���¸� ��ȭ�Ѵ�.
				if (swt[num - j] == swt[num + j]) {
					swt[num - j] = (swt[num - j] + 1) % 2;
					swt[num + j] = swt[num - j];
				}
				else
					break;
			}
			swt[num] = (swt[num] + 1) % 2; // ���簪�� �ٲ۴�
		}
	}

	// ���
	for (int i = 1; i <= T; i++) {
		cout<<swt[i]; // ���� ���
		if (i % 20 == 0)
			cout << endl;
		else
			cout<<" "; // �ƴѰ�� �������
	}
	cout << endl;
}