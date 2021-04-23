#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1005];
vector<int> weight[1005];
vector<int> reverseGraph[1005];
vector<int> reverseWeight[1005];
int length[1005];
int reverseLength[1005];
bool check[1005];
int n, m, k;
const int INF = 1000000;

void getAllToChulsu() {
	for (int i = 1; i <= n; i++) {
		reverseLength[i] = INF;
		check[i] = false;
	}
	reverseLength[k] = 0;
	for (int i = 1; i <= n; i++) {
		int minDistance = INF;
		int minNode = -1;
		for (int j = 1; j <= n; j++) {
			if (!check[j] && reverseLength[j] < minDistance) {
				minDistance = reverseLength[j];
				minNode = j;
			}
		}
		check[minNode] = minNode;
		for (int j = 0; j < reverseGraph[minNode].size(); j++) {
			int node = reverseGraph[minNode][j];
			int cost = reverseWeight[minNode][j];
			if (reverseLength[node] > reverseLength[minNode] + cost) {
				reverseLength[node] = reverseLength[minNode] + cost;
			}
		}
	}
}

void getChulsuToAll() {
	for (int i = 1; i <= n; i++) {
		length[i] = INF;
		check[i] = false;
	}
	length[k] = 0;
	for (int i = 1; i <= n; i++) {
		int minDistance = INF;
		int minNode = -1;
		for (int j = 1; j <= n; j++) {
			if (!check[j] && length[j] < minDistance) {
				minDistance = length[j];
				minNode = j;
			}
		}
		check[minNode] = minNode;
		for (int j = 0; j < graph[minNode].size(); j++) {
			int node = graph[minNode][j];
			int cost = weight[minNode][j];
			if (length[node] > length[minNode] + cost) {
				length[node] = length[minNode] + cost;
			}
		}
	}
}

int main() {
	int a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(b);
		weight[a].push_back(c);
		reverseGraph[b].push_back(a);
		reverseWeight[b].push_back(c);
	}
	getAllToChulsu();
	getChulsuToAll();
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (length[i] + reverseLength[i]);
	}
	cout << sum;
	return 0;
}
