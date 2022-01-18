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
	// 1. ���� �� �� ����
	tmp = Mat[start][lange - 1]; // (1)
	// 2. �ֻ�� �̵� ( start ~ lange-1 )
	for (int i = lange - 2; i >= start; i--) {
		Mat[start][i + 1] = Mat[start][i];
	}

	// 3. ���� �ǳ� ����
	tmp2 = Mat[lange - 1][lange - 1]; // (2)
	// 4. ���� ������
	for (int i = lange - 2; i > start; i--) {
		Mat[i + 1][lange - 1] = Mat[i][lange - 1];
	}
	// 5. 1������ ������ �� ���ڸ��� �̵�
	Mat[start + 1][lange - 1] = tmp;// (1) ��ġ ��
	// 6. ������ ����
	tmp = tmp2;
	// 7. ���ϴ� ���� ����
	tmp2 = Mat[lange - 1][start]; // (3)

	// 8. ���ϴ� �̵�
	for (int i = start; i < lange - 1; i++) {
		Mat[lange - 1][i] = Mat[lange - 1][i + 1];
	}

	// 9. ���尪 ��ġ
	Mat[lange - 1][lange - 2] = tmp; // (2) ��ġ ��

	for (int i = start; i < lange - 1; i++) {
		Mat[i][start] = Mat[i + 1][start];
	}
	Mat[lange - 2][start] = tmp2; // (3) ��ġ��
}

void lotate_Matrix(vector<vector<int>> &Mat) {
	for (int i = 0; i < Mat.size() / 2; i++)
		lotate(Mat, Mat.size() - i);
}

int main() 
{
	vector<vector<int>> Mat;
	int num;
	cout << "Mat�� ������ �Է� >>" << endl;
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