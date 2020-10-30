#include <iostream>
#include <vector>
using namespace std;

int n;
bool* visited;
int* startMembers;
int* linkMembers;
int** arr;
vector<int> difference;

int ability(int* members) {
	int sum = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (j != i) {
				sum += arr[members[i]][members[j]];
			}
		}
	}
	return sum;
}
void divideTeam(int num) {
	if (num == n / 2) {
		int index = 0;
		for (int i = 0; i < n; i++) {
			bool flag = true;
			for (int j = 0; j < n / 2; j++) {
				if (startMembers[j] == i) {
					flag = false;
				}
			}
			if (flag) {
				linkMembers[index] = i;
				index++;
				if (index == n / 2) break;
			}
		}
		difference.push_back(abs(ability(startMembers) - ability(linkMembers)));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (num > 0) {
			if (startMembers[num - 1] < i) {
				if (!visited[i]) {
					startMembers[num] = i;
					visited[i] = true;
					divideTeam(num + 1);
					visited[i] = false;
				}
			}
		}
		else {
			if (!visited[i]) {
				startMembers[num] = i;
				visited[i] = true;
				divideTeam(num + 1);
				visited[i] = false;
			}

		}
	}
}


int main() {
	cin >> n;
	arr = new int*[n];
	visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	startMembers = new int[n / 2];
	linkMembers = new int[n / 2];
	divideTeam(0);
	int minDifference = difference[0];
	for (int i = 1; i < difference.size(); i++) {
		if (difference[i] < minDifference)
			minDifference = difference[i];
	}
	cout << minDifference << endl;
	return 0;
}