#include <iostream>
using namespace std;

char inequal[10];
int result[10];
bool visited[10];
int k;
bool foundMin = false;
bool foundMax = false;

void getMin(int current) {
	if (foundMin) return;
	if (current == k + 1) {
		bool flag = true;
		for (int i = 0; i < k; i++) {
			if (result[i] < result[i + 1] && inequal[i] == '>' || result[i] > result[i + 1] && inequal[i] == '<') {
				flag = false;
				break;
			}
		}
		if (flag) {
			foundMin = true;
			for (int i = 0; i < k + 1; i++) {
				cout << result[i];
			}
		}
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[current] = i;
			getMin(current + 1);
			visited[i] = false;
		}
	}
}

void getMax(int current) {
	if (foundMax) return;
	if (current == k + 1) {
		bool flag = true;
		for (int i = 0; i < k; i++) {
			if (result[i] < result[i + 1] && inequal[i] == '>' || result[i] > result[i + 1] && inequal[i] == '<') {
				flag = false;
				break;
			}
		}
		if (flag) {
			foundMax = true;
			for (int i = 0; i < k + 1; i++) {
				cout << result[i];
			}
		}
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (!visited[i]) {
			visited[i] = true;
			result[current] = i;
			getMax(current + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> inequal[i];
	}
	getMax(0);
	cout << endl;
	for (int i = 0; i <= 9; i++) {
		visited[i] = false;
	}
	getMin(0);
	return 0;
}
