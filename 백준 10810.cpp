#include <iostream>
using namespace std;

int main() {
	int n, m;
	int basket[110] = { 0 };
	cin >> n >> m;
	int from, to, k;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> k;
		for (int j = from - 1; j < to; j++) {
			basket[j] = k;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << basket[i] << " ";
	}
	return 0;
}