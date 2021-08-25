#include <iostream>
using namespace std;

int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = n; i <= m; i++) {
		cout << i << " ";
		cnt++;
		if (cnt == 8) {
			cout << '\n';
			cnt = 0;
		}
	}
	return 0;
}
