#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> image1(n);
	vector<string> image2(n);
	for (int i = 0; i < n; i++) {
		cin >> image1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> image2[i];
	}
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!(image2[i][2 * j] == image2[i][2 * j + 1] && image2[i][2 * j] == image1[i][j])) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	cout << (flag ? "Eyfa" : "Not Eyfa");
	return 0;
}