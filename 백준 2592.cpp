#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int arr[10];
	vector<pair<int, int>> cnt;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		sum += arr[i];
		bool flag = false;
		int index;
		for (int j = 0; j < cnt.size(); j++) {
			if (cnt[j].first == arr[i]) {
				flag = true;
				index = j;
				break;
			}
		}
		if (flag) {
			cnt[index].second++;
		}
		else {
			cnt.push_back(make_pair(arr[i], 1));
		}
	}
	int maxNum = 0;
	int maxValue;
	for (int i = 0; i < cnt.size(); i++) {
		if (cnt[i].second > maxNum) {
			maxNum = cnt[i].second;
			maxValue = cnt[i].first;
		}
	}
	cout << sum / 10 << endl;
	cout << maxValue;
	return 0;
}