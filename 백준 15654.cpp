#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int result[10];
bool visited[10] = { 0 };

void getResult(int current) {
	if (current == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[current] = arr[i];
			getResult(current + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	getResult(0);
	return 0;
}