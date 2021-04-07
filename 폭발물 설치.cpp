#include <iostream>
#include <vector>
using namespace std;

int order[1005];
int index = 0;
vector<int> graph[1005];
bool visited[1005];
int n, m;
int cnt = 0;

void getOrder(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visited[graph[node][i]]) {
			getOrder(graph[node][i]);
		}
	}
	order[index++] = node;
}

void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visited[graph[node][i]]) {
			dfs(graph[node][i]);
		}
	}
}

int main() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			getOrder(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
	for (int i = index - 1; i >= 0; i--) {
		int node = order[i];
		if (!visited[node]) {
			dfs(node);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
