#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;
int n;
int maxOrder = -1;
int maxChaos = -1;
vector<int> maxChaosArray;
vector<int> maxOrderArray;
bool funEnd = false;

void combination(vector<int> result, vector<bool> visited, int num) {
	if (funEnd) return;
	if (num == n) {
		int order = 0;
		int chaos = 0;
		for (int i = 0; i < n; i++) {
			int numOfPeople;
			if(i != n - 1)numOfPeople = result[i] + result[i + 1];
			else numOfPeople = result[n - 1] + result[0];
			bool flag = false;
			for (int i = 2; i < numOfPeople / 2 + 1; i++) {
				if (numOfPeople % i == 0) {
					flag = true;
					break;
				}
			}
			if (flag) order++;
			else chaos++;
		}

		if (s == "chaos") {
			if (chaos > maxChaos) {
				maxChaos = chaos;
				for (int i = 0; i < n; i++) {
					maxChaosArray[i] = result[i];
				}
				if (maxChaos == n) { 
					funEnd = true;
				}
			}
		}
		else {
			if (order > maxOrder) {
				maxOrder = order;
				for (int i = 0; i < n; i++) {
					maxOrderArray[i] = result[i];
				}
				if (maxOrder == n) {
					funEnd = true;
				}
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[num] = i + 1;
			combination(result, visited, num + 1);
			visited[i] = false;
		}
	}
}


int main() {
	cin >> s >> n;
	vector<int> result(n);
	vector<bool> visited(n);
	if (s == "chaos") {
		for (int i = 0; i < n; i++) {
			maxChaosArray.push_back(0);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			maxOrderArray.push_back(0);
		}
	}
	combination(result, visited, 0);
	if (s == "chaos") {
		for (int i = 0; i < n; i++) {
			cout << maxChaosArray[i] << " ";
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << maxOrderArray[i] << " ";
		}
	}
	return 0;
}