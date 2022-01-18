#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> &Mat) {
	cout << Mat.size() << endl;
	for (int i = 0; i < Mat.size(); i++) {
		for (int j = 0; j < Mat[i].size(); j++) {
			cout<<Mat[i][j]<< "\t";
		}
		cout << endl;
	}
}

void lotate(vector<vector<int>>& Mat, int lange) {
	int tmp, tmp2;
	int start = Mat.size() - lange;
	// 1. 가로 맨 끝 보관
	tmp = Mat[start][lange - 1]; // (1)
	// 2. 최상단 이동 ( start ~ lange-1 )
	for (int i = lange - 2; i >= start; i--) {
		Mat[start][i + 1] = Mat[start][i];
	}

	// 3. 세로 맨끝 보관
	tmp2 = Mat[lange - 1][lange - 1]; // (2)
	// 4. 세로 내리기
	for (int i = lange - 2; i > start; i--) {
		Mat[i + 1][lange - 1] = Mat[i][lange - 1];
	}
	// 5. 1번에서 보관한 값 제자리로 이동
	Mat[start + 1][lange - 1] = tmp;// (1) 배치 완
	// 6. 보관값 갱신
	tmp = tmp2;
	// 7. 최하단 가로 저장
	tmp2 = Mat[lange - 1][start]; // (3)

	// 8. 최하단 이동
	for (int i = start; i < lange - 1; i++) {
		Mat[lange - 1][i] = Mat[lange - 1][i + 1];
	}

	// 9. 저장값 배치
	Mat[lange - 1][lange - 2] = tmp; // (2) 배치 완

	for (int i = start; i < lange - 1; i++) {
		Mat[i][start] = Mat[i + 1][start];
	}
	Mat[lange - 2][start] = tmp2; // (3) 배치완
}

void lotate_Matrix(vector<vector<int>> &Mat) {
	for (int i = 0; i < Mat.size() / 2; i++)
		lotate(Mat, Mat.size() - i);
}

int main() 
{
	vector<vector<int>> Mat;
	int num;
	cout << "Mat의 사이즈 입력 >>" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		vector<int> vec;
		for (int j = 0; j < num; j++) {		
			vec.push_back(i * num + j + 1);		
		}
		Mat.push_back(vec);
	}

	cout << "Original Matrix" << endl;
	print(Mat);

	for (int i = 1; i <= 4; i++) {
		cout << endl;
		lotate_Matrix(Mat);
		cout<<i <<"th lotate Matrix"<<endl;
		print(Mat);
	}

}