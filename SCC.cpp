#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> graph[1005];
vector<int> reverseGraph[1005];
int second = 1;
bool visited[1005];
bool reverseVisited[1005];
int order[1005];
int index = 0;
int cnt = 0;

void getTime(int node) {
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (!visited[graph[node][i]]) getTime(graph[node][i]);
	}
	order[index++] = node;
}

void getMyGroup(int node) {
	reverseVisited[node] = true;
	for (int i = 0; i < reverseGraph[node].size(); i++) {
		if (!reverseVisited[reverseGraph[node][i]]) {
			getMyGroup(reverseGraph[node][i]);
		}
	}
}

int main() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		reverseGraph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			getTime(i);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		int node = order[i];
		if (!reverseVisited[node]) {
			getMyGroup(node);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
