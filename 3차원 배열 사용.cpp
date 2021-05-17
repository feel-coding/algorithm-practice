#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[105][105];

int main() {
	int n, m, q, t, y, x, w;
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1 || t == 2) {
			cin >> y >> x >> w;
			if (t == 1) {
				arr[y][x].push_back(w);
			}
			else {
				arr[y][x].insert(arr[y][x].begin(), w);
			}
		}
		else {
			cin >> y >> x;
			if (t == 3) {
				arr[y][x].erase(arr[y][x].begin() + arr[y][x].size() - 1);
			}
			else {
				cout << arr[y][x][arr[y][x].size() - 1] << '\n';
			}
		}
	}
	return 0;
}
