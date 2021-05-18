#include <iostream>
using namespace std;

int arr[105][105][105];
int cnt[105][105];

int main() {
	int n, m, q, t, y, x, w, c;
	cin >> n >> m >> q;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t <= 2) {
			cin >> y >> x >> w >> c;
			if (t == 1) {
				for (int j = 0; j < c; j++) {
					arr[y][x][cnt[y][x]++] = w;
				}
			}
			else {
				for (int j = cnt[y][x] + c - 1; j >= c; j--) {
					arr[y][x][j] = arr[y][x][j - c];
				}
				cnt[y][x] += c;
				for (int j = 0; j < c; j++) {
					arr[y][x][j] = w;
				}
			}
		}
		else {
			cin >> y >> x;
			if (t == 3) {
				cin >> c;
				cnt[y][x] -= c;
			}
			else {
				cout << arr[y][x][cnt[y][x] - 1] << '\n';
			}
		}
	}
	return 0;
}
