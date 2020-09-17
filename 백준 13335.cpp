#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	int n, w, l;
	cin >> n >> w >> l;
	vector<int> v(n);
	queue<int> q;
	vector<int> count;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	q.push(v[0]);
	count.push_back(w);
	int index = 1;
	int time = 1;
	int totalWeight = v[0];
	int weight;
	while (!q.empty()) {
		for (int i = 0; i < count.size(); i++) {
			count[i]--;
		}
		if (count[0] == 0) {
			weight = q.front();
			q.pop();
			totalWeight -= weight;
			count.erase(count.begin());
		}
		if (index < n && totalWeight + v[index] <= l) {
			q.push(v[index]);
			count.push_back(w);
			totalWeight += v[index];
			index++;
		}
		time++;
	}
	cout << time;
	return 0;
}