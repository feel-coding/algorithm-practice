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
	sort(arr, arr + n);
	int num;
	for (int i = 0; i < q; i++) {
		cin >> num;
		cout << upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num) << '\n';
	}
	return 0;
}
