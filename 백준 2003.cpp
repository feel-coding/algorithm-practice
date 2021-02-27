#include <iostream>
using namespace std;

int arr[10005] = { 0 };
int sum[10005] = { 0 };

int main() {
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int start = i;
		int end = n + 1;
		int mid;
		while (start + 1 < end) {
			mid = (start + end) / 2;
			if (sum[mid] - sum[i - 1] <= m) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		if (sum[start] - sum[i - 1] == m) cnt++;
	}
	cout << cnt;
	return 0;
}
