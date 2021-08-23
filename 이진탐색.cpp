#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int num;
	for (int i = 0; i < q; i++) {
		cin >> num;
		if (binary_search(arr, arr + n, num)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}
