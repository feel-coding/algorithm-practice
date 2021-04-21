#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[10005];
bool check[10005];
int length[10005];
const int INF = 10000000;

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		length[i] = INF;
	}
	length[a] = 0;
	for (int i = 0; i < n; i++) {
		int minDistance = INF, minNode = -1;
		for (int j = 0; j < n; j++) {
			if (!check[j] && length[j] < minDistance) {
				minDistance = length[j];
				minNode = j;
			}
		}
		check[minNode] = true;
		for (int j = 0; j < graph[minNode].size(); j++) {
			int node = graph[minNode][j];
			if (length[node] > length[minNode] + 1) {
				length[node] = length[minNode] + 1;
			}
		}
	}
	cout << length[b];
	return 0;
}