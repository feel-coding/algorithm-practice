#include <iostream>
#include <vector>
using namespace std;

int arr[100005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 1;
	int end = n + 1;
	int mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		vector<int> cnt(n + 1, 0);
		int duplicateCnt = 0;
		bool flag = false;
		for (int i = 0; i < mid; i++) {
			if (cnt[arr[i]] == 1) {
				duplicateCnt++;
			}
			cnt[arr[i]]++;
		}
		if (duplicateCnt > 0) {
			for (int i = 1; i <= n - mid; i++) {
				cnt[arr[i - 1]]--;
				if (cnt[arr[i - 1]] == 1) {
					duplicateCnt--;
				}
				cnt[arr[i + mid - 1]]++;
				if (cnt[arr[i + mid - 1]] == 2) {
					duplicateCnt++;
				}
				if (duplicateCnt == 0) {
					flag = true;
					break;
				}
			}
		}
		else flag = true;
		if (flag) {
			start = mid;
		}
		else end = mid;
	}
	cout << start;
	return 0;
}
