#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int n;
set<long long> s;
long long number;


void permutation(int num, vector<int> result) {
	if (num == result.size()) {
		number = 0;
		for (int i = result.size() - 1; i >= 0; i--) {
			number += (pow(10, result.size() - 1 - i) * result[i]);
		}
		s.insert(number);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (result.size() - num - 1 <= i && (num == 0 || (num > 0 && result[num - 1] > i))) {
			result[num] = i;
			permutation(num + 1, result);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	int i = 1;
	for (int i = 1; i <= 10; i++) {
		permutation(0, vector<int>(i));
	}
	int cnt = 0;
	bool flag = false;
	for (set<long long>::iterator iter = s.begin(); iter != s.end(); iter++) {
		if (cnt == n) {
			cout << *iter;
			flag = true;
			break;
		}
		cnt++;
	}
	if (!flag)
		cout << -1;
	return 0;
}