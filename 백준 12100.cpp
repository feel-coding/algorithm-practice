#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	int maxNum = 0;
	stack<pair<vector<vector<int>>, int>> s;
	s.push(make_pair(v, 0));
	while (!s.empty()) {
		pair<vector<vector<int>>, int> cur = s.top();
		s.pop();
		vector<vector<int>> status = cur.first;
		int cnt = cur.second;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (status[i][j] > maxNum) {
					maxNum = status[i][j];
				}
			}
		}
		if (cnt < 5) {
			// 위
			vector<vector<int>> temp1 = status;
			for (int j = 0; j < n; j++) {
				vector<int> temp;
				for (int i = 0; i < n; i++) {
					if (temp1[i][j] != 0) {
						temp.push_back(temp1[i][j]);
					}
				}
				int index = 0;
				while (true) {
					if (index >= temp.size())
						break;
					if (index + 1 < temp.size()) {
						if (temp[index] == temp[index + 1]) {
							temp[index] *= 2;
							temp.erase(temp.begin() + index + 1);
						}
					}
					index++;
				}
				for (int i = 0; i < temp.size(); i++) {
					temp1[i][j] = temp[i];
				}
				for (int i = temp.size(); i < n; i++) {
					temp1[i][j] = 0;
				}
			}
			s.push(make_pair(temp1, cnt + 1));
			// 왼쪽
			vector<vector<int>> temp2 = status;
			for (int i = 0; i < n; i++) {
				vector<int> temp;
				for (int j = 0; j < n; j++) {
					if (temp2[i][j] != 0) {
						temp.push_back(temp2[i][j]);
					}
				}
				int index = 0;
				while (true) {
					if (index >= temp.size())
						break;
					if (index + 1 < temp.size()) {
						if (temp[index] == temp[index + 1]) {
							temp[index] *= 2;
							temp.erase(temp.begin() + index + 1);
						}
					}
					index++;
				}
				for (int j = 0; j < temp.size(); j++) {
					temp2[i][j] = temp[j];
				}
				for (int j = temp.size(); j < n; j++) {
					temp2[i][j] = 0;
				}
			}
			s.push(make_pair(temp2, cnt + 1));
			// 아래
			vector<vector<int>> temp3 = status;
			for (int j = 0; j < n; j++) {
				vector<int> temp;
				for (int i = n - 1; i >= 0; i--) {
					if (temp3[i][j] != 0) {
						temp.push_back(temp3[i][j]);
					}
				}
				int index = 0;
				while (true) {
					if (index >= temp.size())
						break;
					if (index + 1 < temp.size()) {
						if (temp[index] == temp[index + 1]) {
							temp[index] *= 2;
							temp.erase(temp.begin() + index + 1);
						}
					}
					index++;
				}
				for (int i = 0; i < temp.size(); i++) {
					temp3[n - 1 - i][j] = temp[i];
				}
				for (int i = n - 1 - temp.size(); i >= 0; i--) {
					temp3[i][j] = 0;
				}
			}
			s.push(make_pair(temp3, cnt + 1));
			// 오른쪽
			vector<vector<int>> temp4 = status;
			for (int i = 0; i < n; i++) {
				vector<int> temp;
				for (int j = n - 1; j >= 0; j--) {
					if (temp4[i][j] != 0) {
						temp.push_back(temp4[i][j]);
					}
				}
				int index = 0;
				while (true) {
					if (index >= temp.size())
						break;
					if (index + 1 < temp.size()) {
						if (temp[index] == temp[index + 1]) {
							temp[index] *= 2;
							temp.erase(temp.begin() + index + 1);
						}
					}
					index++;
				}
				for (int j = 0; j < temp.size(); j++) {
					temp4[i][n - 1 - j] = temp[j];
				}
				for (int j = n - 1 - temp.size(); j >= 0; j--) {
					temp4[i][j] = 0;
				}
			}
			s.push(make_pair(temp4, cnt + 1));

		}
	}
	cout << maxNum;
	return 0;
}
