#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[300005];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m, num;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << binary_search(arr, arr + n, num) << '\n';
	}
	return 0;
}
