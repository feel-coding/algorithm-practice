#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int n;
vector<int> v[1001];


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	int day, score;
	int maxDay = 0;
	for (int i = 0; i < n; i++) {
		cin >> day >> score;
		v[day].push_back(score);
		if (day > maxDay)
			maxDay = day;
	}
	int sum = 0;
	for (int i = 1; i <= maxDay; i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = maxDay; i >= 1; i--) {
		int maxScore = -1;
		int maxJ;
		for (int j = i; j <= maxDay; j++) {
			//erase 꼭 하기
			if (v[j].size() != 0) {
				if (v[j][v[j].size() - 1] > maxScore) {
					maxScore = v[j][v[j].size() - 1];
					maxJ = j;
				}
			}
		}
		if (maxScore != -1) {
			sum += maxScore;
			v[maxJ].erase(v[maxJ].begin() + v[maxJ].size() - 1);
		}

	}
	cout << sum;
	return 0;
}