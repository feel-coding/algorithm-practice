#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> arr[105][105];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
string direction[4] = { "╩С", "го", "аб", "©Л" };
int reverseDirection[4] = { 1, 0, 3, 2 };
int people[105][3];

int main() {
	int n, m, k, t, y, x, d;
	cin >> n >> m >> k >> t;
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> d;
		people[i][0] = y;
		people[i][1] = x;
		people[i][2] = d;
		arr[y][x].push_back(i);
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < k; j++) {
			int row = people[j][0];
			int col = people[j][1];
			d = people[j][2];
			int nr = row + dr[d];
			int nc = col + dc[d];
			if (nr < 1) {
				d = reverseDirection[d];
				nr = row + dr[d];
			}
			else if (nc < 1) {
				d = reverseDirection[d];
				nc = col + dc[d];
			}
			else if (nr > n) {
				d = reverseDirection[d];
				nr = row + dr[d];
			}
			else if (nc > m) {
				d = reverseDirection[d];
				nc = col + dc[d];
			}
			for (int p = 0; p < arr[row][col].size(); p++) {
				arr[nr][nc].push_back(arr[row][col][p]);
				people[arr[row][col][p]][0] = nr;
				people[arr[row][col][p]][1] = nc;
			}
			arr[row][col] = vector<int>();
			people[j][2] = d;
		}
	}
	for (int i = 0; i < k; i++) {
		cout << people[i][0] << " " << people[i][1] << endl;
	}
	return 0;
}
