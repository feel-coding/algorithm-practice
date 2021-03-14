#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1005];
vector<int> weight[1005];
long long length[1005];
bool check[1005];
int n, m;
const long long INF = 25000000000;

long long getMinDistance(int from, int to) {
	for (int i = 1; i <= n; i++) {
		length[i] = INF;
		check[i] = false;
	}
	length[from] = 0;
	for (int i = 1; i <= n; i++) {
		long long minDistance = INF;
		int minNode = -1;
		for (int j = 1; j <= n; j++) {
			if (!check[j] && length[j] < minDistance) {
				minDistance = length[j];
				minNode = j;
			}
		}
		check[minNode] = true;
		for (int j = 0; j < graph[minNode].size(); j++) {
			int node = graph[minNode][j];
			int cost = weight[minNode][j];
			if (length[node] > length[minNode] + cost) {
				length[node] = length[minNode] + cost;
			}
		}
	}
	return length[to];
}

int main() {
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(b);
		weight[a].push_back(c);
		graph[b].push_back(a);
		weight[b].push_back(c);
	}
	cin >> a >> b;
	long long oneToA = getMinDistance(1, a);
	long long oneToB = getMinDistance(1, b);
	long long aToB = getMinDistance(a, b);
	long long aToN = getMinDistance(a, n);
	long long bToN = getMinDistance(b, n);
	cout << min(oneToA + aToB + bToN, oneToB + aToB + aToN);
	return 0;
}