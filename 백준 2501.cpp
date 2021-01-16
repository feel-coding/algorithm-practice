#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	int answer = -1;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (cnt == k) {
				answer = i;
				break;
			}
		}
	}
	cout << (answer == -1 ? 0 : answer);
	return 0;
}
