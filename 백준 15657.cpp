#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;

void select(vector<int> result, int num) {
	if (num == k) {
		for (int i = 0; i < k; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (num == 0) {
			result[num] = v[i];
			select(result, num + 1);
		}
		else {
			if (result[num - 1] <= v[i]) {
				result[num] = v[i];
				select(result, num + 1);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	v = vector<int>(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	select(vector<int>(k), 0);
	return 0;
}