#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int girls[6] = { 0, };
	int boys[6] = { 0, };
	int s, y;
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		if (s == 0) {
			girls[y - 1]++;
		}
		else {
			boys[y - 1]++;
		}
	}
	int room = 0;
	for (int i = 0; i < 6; i++) {
		if (girls[i] % k == 0) {
			room += (girls[i] / k);
		}
		else {
			room += (girls[i] / k + 1);
		}
		if (boys[i] % k == 0) {
			room += (boys[i] / k);
		}
		else {
			room += (boys[i] / k + 1);
		}
	}
	cout << room;
	return 0;
}