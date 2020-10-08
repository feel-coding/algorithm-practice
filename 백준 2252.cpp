#include <iostream>
#include <queue>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> student[32001];
	vector<int> inDegree(n + 1);
	for (int i = 0; i < m; i++) {
		int shorter, taller;
		cin >> shorter>> taller;
		student[shorter].push_back(taller);
		inDegree[taller]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < student[cur].size(); i++) {
			inDegree[student[cur][i]]--;
			if (inDegree[student[cur][i]] == 0) q.push(student[cur][i]);
		}
	}
	return 0;
}