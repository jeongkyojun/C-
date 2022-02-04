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
			// 남성인경우
			for (int j = num; j <= T; j += num) {
				swt[j] = (swt[j] + 1) % 2;
			}
		}
		else {
			// 여성인경우
			for (int j = 1; j <= T; j++) { // n+i 와 n-i를 비교, 같으면 바꾼다.
				// 예외 발생시 break
				if (num - j <= 0 || num + j > T) // 범위를 벗어나면 종료한다.
					break;
				// 대칭되는경우 상태를 변화한다.
				if (swt[num - j] == swt[num + j]) {
					swt[num - j] = (swt[num - j] + 1) % 2;
					swt[num + j] = swt[num - j];
				}
				else
					break;
			}
			swt[num] = (swt[num] + 1) % 2; // 현재값을 바꾼다
		}
	}

	// 출력
	for (int i = 1; i <= T; i++) {
		cout<<swt[i]; // 값을 출력
		if (i % 20 == 0)
			cout << endl;
		else
			cout<<" "; // 아닌경우 띄워쓰기
	}
	cout << endl;
}