#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool arr[1299710] = { false };
int where[1299710] = { 0 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<int> primeNumber;
	arr[1] = true;
	for (int i = 2; i <= 1299709; i++) {
		if (!arr[i]) {
			primeNumber.push_back(i);
			where[i] = primeNumber.size() - 1;
			for (int j = 2; ; j++) {
				if (j * i > 1299709) break;
				arr[i * j] = true;
			}
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (arr[num]) {
			for (int j = num - 1; ; j--) {
				if (!arr[j]) {
					cout << primeNumber[where[j] + 1] - primeNumber[where[j]] << '\n';
					break;
				}
			}
		}
		else cout << 0 << '\n';
	}
	return 0;
}