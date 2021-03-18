#include <iostream>
using namespace std;

int arr[20][10];
bool visited[10];
int specialLecture;
bool foundAnswer;
int p, n, k;
int result[10];
int scoreResult[10];

bool isUpward(int scores[], int size) { // k번 연속으로 오르는지 알려주는 함수
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

void pickScore(int current) { // 특강을 했을 때 특정 문제의 GR지수를 정해주는 함수
	if (foundAnswer) return;
	if (current == specialLecture) {
		int tempArr[20][10];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				tempArr[i][j] = arr[i][j];
			}
		}
		for (int j = 0; j < specialLecture; j++) {
			int problem = result[j]; // 몇 번 문제?
			int gr = scoreResult[j]; // 몇 점으로?
			for (int i = 0; i < n; i++) { // 1번 학생부터 n번 학생까지
				tempArr[i][problem] = gr; // problem번 문제의 GR지수를 gr로 고친다
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


void pickProblems(int current) { // 몇 번 문제를 특강을 할지 정하는 함수
	if (foundAnswer) return;
	if (current == specialLecture) {
		pickScore(0); // 몇 번 문제를 특강할지는 정해졌고 GR지수를 몇으로 맞출지 정한다
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
		for (int i = 1; i <= p; i++) { // 1문제 특강할 경우 ~ p개 문제 특강할 경우
			specialLecture = i; // 몇 문제를 특강할지 결정
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