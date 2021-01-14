#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	vector<string> primeNumbers;
	map<string, int> map;
	for (int i = 1000; i <= 9999; i++) {
		int flag = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			primeNumbers.push_back(to_string(i));
			map[to_string(i)] = primeNumbers.size() - 1;
		}
	}
	string from, to;
	for (int t = 0; t < testCase; t++) {
		vector<bool> visited(primeNumbers.size(), false);
		cin >> from >> to;
		queue<pair<string, int>> q;
		q.push(make_pair(from, 0));
		bool found = false;
		while (!q.empty()) {
			pair<string, int> cur = q.front();
			q.pop();
			if (cur.first == to) {
				cout << cur.second << '\n';
				found = true;
				break;
			}
			if (!visited[map[cur.first]]) {
				visited[map[cur.first]] = true;
				for (char i = '1'; i <= '9'; i++) {
					if (cur.first[0] == i)
						continue;
					string temp = cur.first;
					temp[0] = i;
					if (binary_search(primeNumbers.begin(), primeNumbers.end(), temp)) {
						if (!visited[map[temp]])
							q.push(make_pair(temp, cur.second + 1));
					}
				}
				for (char i = '0'; i <= '9'; i++) {
					if (cur.first[1] == i)
						continue;
					string temp = cur.first;
					temp[1] = i;
					if (binary_search(primeNumbers.begin(), primeNumbers.end(), temp)) {
						if (!visited[map[temp]])
							q.push(make_pair(temp, cur.second + 1));
					}
				}
				for (char i = '0'; i <= '9'; i++) {
					if (cur.first[2] == i)
						continue;
					string temp = cur.first;
					temp[2] = i;
					if (binary_search(primeNumbers.begin(), primeNumbers.end(), temp)) {
						if (!visited[map[temp]])
							q.push(make_pair(temp, cur.second + 1));
					}
				}
				for (char i = '0'; i <= '9'; i++) {
					if (cur.first[3] == i)
						continue;
					string temp = cur.first;
					temp[3] = i;
					if (binary_search(primeNumbers.begin(), primeNumbers.end(), temp)) {
						if (!visited[map[temp]])
							q.push(make_pair(temp, cur.second + 1));
					}
				}
			}
		}
		if (!found) {
			cout << "Impossible\n";
		}
	}
	return 0;
}
