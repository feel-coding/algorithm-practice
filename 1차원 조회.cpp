#include <iostream>
using namespace std;

int main() {
	int arr[1005];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	arr[0] = -1;
	arr[n + 1] = -1;
	for (int i = 1; i <= n; i++) {
		if (arr[i - 1] == arr[i] || arr[i + 1] == arr[i]) {
			cout << 1 << " ";
		}
		else {
			cout << 0 << " ";
		}
	}
	return 0;
}
