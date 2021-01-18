#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> alphabetNum(8, vector<int>(26, 0));
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = s.size() - 1; j >= 0; j--) {
			alphabetNum[s.size() - 1 - j][s[j] - 'A']++;
		}
	}
	vector<int> tempCount(26, 0);
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 8; i++) {
			if (alphabetNum[i][j] != 0) {
				tempCount[j] += pow(10, i) * alphabetNum[i][j];
			}
		}
	}
	sort(tempCount.begin(), tempCount.end());
	int num = 9;
	int total = 0;
	for (int i = tempCount.size() - 1; i >= 0; i--) {
		if (tempCount[i] == 0)
			break;
		total += tempCount[i] * num;
		num--;
	}
	cout << total;
	return 0;
}
