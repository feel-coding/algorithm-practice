#include <iostream>
using namespace std;

int arr[20][10];
bool visited[10];
int specialLecture;
bool foundAnswer;
int p, n, k;
int result[10];
int scoreResult[10];

bool isUpward(int scores[], int size) { // k�� �������� �������� �˷��ִ� �Լ�
	for (int i = 0; i <= size - k; i++) {
		bool flag = true;
		for (int j = 0; j < k - 1; j++) {
			if (scores[i + j] > scores[i + j + 1]) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	}
	return false;
}

void pickScore(int current) { // Ư���� ���� �� Ư�� ������ GR������ �����ִ� �Լ�
	if (foundAnswer) return;
	if (current == specialLecture) {
		int tempArr[20][10];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				tempArr[i][j] = arr[i][j];
			}
		}
		for (int j = 0; j < specialLecture; j++) {
			int problem = result[j]; // �� �� ����?
			int gr = scoreResult[j]; // �� ������?
			for (int i = 0; i < n; i++) { // 1�� �л����� n�� �л�����
				tempArr[i][problem] = gr; // problem�� ������ GR������ gr�� ��ģ��
			}
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (!isUpward(tempArr[i], p)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			foundAnswer = true;
		}
		return;
	}
	for (int i = 1; i <= 5; i++) {
		if (current == 0) {
			scoreResult[current] = i;
			pickScore(current + 1);
		}
		else if (scoreResult[current - 1] <= i) {
			scoreResult[current] = i;
			pickScore(current + 1);
		}

	}
}


void pickProblems(int current) { // �� �� ������ Ư���� ���� ���ϴ� �Լ�
	if (foundAnswer) return;
	if (current == specialLecture) {
		pickScore(0); // �� �� ������ Ư�������� �������� GR������ ������ ������ ���Ѵ�
		return;
	}
	for (int i = 0; i < p; i++) {
		if (!visited[i]) {
			if (current == 0) {
				visited[i] = true;
				result[current] = i;
				pickProblems(current + 1);
				visited[i] = false;
			}
			else if (result[current - 1] < i) {
				visited[i] = true;
				result[current] = i;
				pickProblems(current + 1);
				visited[i] = false;
			}
		}
	}
}

void initVisited() {
	for (int i = 0; i < p; i++) {
		visited[i] = false;
	}
}

int main() {
	int testCase;
	char score;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> p >> n >> k;
		for (int j = 0; j < p; j++) {
			for (int i = 0; i < n; i++) {
				cin >> score;
				if (score == 'S') {
					arr[i][j] = 5;
				}
				else if (score == 'A') {
					arr[i][j] = 4;
				}
				else if (score == 'B') {
					arr[i][j] = 3;
				}
				else if (score == 'C') {
					arr[i][j] = 2;
				}
				else if (score == 'D') {
					arr[i][j] = 1;
				}
				else if (score == 'F') {
					arr[i][j] = 0;
				}
			}
		}
		foundAnswer = false;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (!isUpward(arr[i], p)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "#" << t << " " << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= p; i++) { // 1���� Ư���� ��� ~ p�� ���� Ư���� ���
			specialLecture = i; // �� ������ Ư������ ����
			initVisited();
			pickProblems(0);
			if (foundAnswer) {
				cout << "#" << t << " " << i << '\n';
				break;
			}
		}
	}
	return 0;
}