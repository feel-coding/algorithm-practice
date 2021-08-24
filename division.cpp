#include <iostream>
using namespace std;

int n;
int result[30];
int cnt = 0;

void getResult(int current, int sum) {
	if (current > n) return;
	if (sum > n) return;
	if (sum == n) {
		cnt++;
		for (int i = 0; i < current; i++) {
			cout << result[i];
			if (i != current - 1) {
				cout << "+";
			}
		}
		cout << '\n';
		return;
	}
	for (int i = n - 1; i >= 1; i--) {
		if (current == 0) {
			result[current] = i;
			getResult(current + 1, sum + i);
		}
		else if (result[current - 1] >= i) {
			result[current] = i;
			getResult(current + 1, sum + i);
		}
	}
}

int main() {
	cin >> n;
	getResult(0, 0);
	cout << cnt;
	return 0;
}
