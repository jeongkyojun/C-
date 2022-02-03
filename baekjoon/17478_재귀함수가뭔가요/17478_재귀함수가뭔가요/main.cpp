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
	string line1 = "\"����Լ��� ������?\"";
	string line2 = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
	string line3 = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
	string line4 = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
	string line5 = "��� �亯�Ͽ���.";
	string answer = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";

	int n;
	cin >> n;
	cout<<"��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."<<endl;
	Recur(line1, line2, line3, line4, line5, answer, 0, n);
}