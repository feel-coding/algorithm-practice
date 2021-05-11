#include <iostream>
using namespace std;

int n, k;
int cnt = 0;
bool flag = false;
int angle[4] = { 0, 90, 180, 270 };
int result[10];

void getResult(int current) {
	if (flag) return;
	if (current == n) {
		cnt++;
		if (cnt == k) {
			flag = true;
			for (int i = 0; i < n; i++) {
				cout << angle[result[i]] << " ";
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		result[current] = i;
		getResult(current + 1);

	}
}

int main() {
	cin >> n >> k;
	getResult(0);
	return 0;
}
