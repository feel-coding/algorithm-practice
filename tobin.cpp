#include <iostream>
using namespace std;

int n, k;
int result[30];

void getResult(int index, int cnt) {
	if (cnt > k) return;
	if (index > n) return;
	if (index == n && cnt < k) return;
	if (index == n && cnt == k) {
		for (int i = 0; i < n; i++) {
			cout << result[i];
		}
		cout << '\n';
		return;
	}
	result[index] = 1;
	getResult(index + 1, cnt + 1);
	result[index] = 0;
	getResult(index + 1, cnt);
}

int main() {
	cin >> n >> k;
	getResult(0, 0);
	return 0;
}
