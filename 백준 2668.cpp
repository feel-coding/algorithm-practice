#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> m;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		m[i] = temp;
	}
	vector<int> answer;
	vector<int> real;
	vector<bool> visited(n + 1, false);
	for (int i = 1; i <= n; i++) {
		
		vector<bool> tempVisited(n + 1, false);
		int count = 0;
		int key = i;
		answer.clear();
		if (!visited[i]) {
			while (true) {
				tempVisited[key] = true;
				key = m[key];
				answer.push_back(key);
				count++;
				if (tempVisited[key]) {
					if (key != i) {
						answer.clear();
					}
					break;
				}
			}
		}

		for (int i = 0; i < answer.size(); i++) {
			int index = answer[i];
			visited[index] = true;
		}
		
		//cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			real.push_back(i);
		}
	}
	sort(real.begin(), real.end());
	cout << real.size() << '\n';
	for (int i = 0; i < real.size(); i++) {
		cout << real[i] << '\n';
	}
	return 0;
}