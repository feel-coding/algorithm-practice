#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> w[10];
vector<int> difference;
vector<int> population;

bool isMemberOf(vector<int> v, int num) {
	bool isIn = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == num) {
			isIn = true;
			break;
		}
	}
	return isIn;
}

void divide(vector<bool> visited, vector<int> result, int count, int num) {
	if (count == num) {
		vector<int> others;
		for (int i = 0; i < n; i++) {
			bool found = false;
			for (int j = 0; j < result.size(); j++) {
				if (i == result[j]) {
					found = true;
					break;
				}
			}
			if (!found) others.push_back(i);
		}
		visited = vector<bool>(n);
		queue<int> q;
		q.push(result[0]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			visited[cur] = true;
			for (int i = 0; i < w[cur].size(); i++) {
				if (!visited[w[cur][i]] && isMemberOf(result, w[cur][i]))
					q.push(w[cur][i]);
			}
		}
		q.push(others[0]);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			visited[cur] = true;
			for (int i = 0; i < w[cur].size(); i++) {
				if (!visited[w[cur][i]] && isMemberOf(others, w[cur][i]))
					q.push(w[cur][i]);
			}
		}
		bool allVisited = true;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				allVisited = false;
				break;
			}
		}
		if (allVisited) {
			int sumOfResult = 0;
			int sumOfOthers = 0;
			for (int i = 0; i < result.size(); i++) {
				sumOfResult += population[result[i]];
			}
			for (int i = 0; i < others.size(); i++) {
				sumOfOthers += population[others[i]];
			}
			difference.push_back(abs(sumOfResult - sumOfOthers));
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (num == 0) {
				visited[i] = true;
				result[num] = i;
				divide(visited, result, count, num + 1);
				visited[i] = false;
			}
			else {
				if (result[num - 1] < i) {
					visited[i] = true;
					result[num] = i;
					divide(visited, result, count, num + 1);
					visited[i] = false;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	population = vector<int>(n);
	for(int i = 0; i < n; i++)
		cin >> population[i];
	for (int i = 0; i < n; i++) {
		int count;
		cin >> count;
		for (int j = 0; j < count; j++) {
			int to;
			cin >> to;
			w[i].push_back(to - 1);
		}
	}
	for (int i = 1; i <= n / 2; i++) {
		vector<bool> visited(n);
		vector<int> result(i);
		divide(visited, result, i, 0);
	}
	if (difference.size() > 0) {
		int minDiff = 1000;
		for (int i = 0; i < difference.size(); i++) {
			if (difference[i] < minDiff) minDiff = difference[i];
		}
		cout << minDiff;
	}
	else cout << -1;
	return 0;
}