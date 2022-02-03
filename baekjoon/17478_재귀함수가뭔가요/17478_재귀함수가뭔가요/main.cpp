#include<iostream>

using namespace std;

void Recur(string line1, string line2, string line3, string line4, string line5, string answer, int n, int end) {
	string head = "";
	for (int i = 0; i < n; i++) {
		head += "____";
	}
	if (n == end) {
		cout<<head + line1<<endl;
		cout << head + answer<<endl;
		cout << head + line5 << endl;
		return;
	}
	else {
		cout << head + line1<<endl;
		cout << head + line2<<endl;
		cout << head + line3<<endl;
		cout << head + line4<<endl;
		Recur(line1, line2, line3, line4, line5, answer, n + 1, end);
		cout << head + line5<<endl;
		return;
	}
}

int main() {
	string line1 = "\"재귀함수가 뭔가요?\"";
	string line2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
	string line3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
	string line4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
	string line5 = "라고 답변하였지.";
	string answer = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";

	int n;
	cin >> n;
	cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<endl;
	Recur(line1, line2, line3, line4, line5, answer, 0, n);
}