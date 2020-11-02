#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int count = 0;
		for (int j = 5; j <= num; j *= 5) {
			count += num / j;
		}
		cout << count << '\n';
	}
	return 0;
}