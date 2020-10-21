#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int** arr;
int n;
vector<int> profit;

void select(vector<bool> visited, vector<tuple<int, int, int>> result, int theNumberOfSelect, int num) {

	if (num == theNumberOfSelect) {

		int total = 0;
		if (get<2>(result[0]) + get<0>(result[0]) > n) {
			return;
		}
		for (int i = 1; i < theNumberOfSelect; i++) {
			if (get<2>(result[i]) + get<0>(result[i]) > n) {
				return;
			}
			if (get<2>(result[i - 1]) + get<0>(result[i - 1]) > get<2>(result[i])) {
				return;
			}
		}
		for (int i = 0; i < theNumberOfSelect; i++) {
			total += get<1>(result[i]);
		}

		profit.push_back(total);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (num != 0) {
			if (get<2>(result[num - 1]) < i) {
				if (!visited[i]) {
					visited[i] = true;
					result[num] = make_tuple(arr[i][0], arr[i][1], i); //걸리는 기간, 받는 금액, 시작 날짜
					select(visited, result, theNumberOfSelect, num + 1);
					visited[i] = false;
				}
			}
		}
		else {
			if (!visited[i]) {
				visited[i] = true;
				result[num] = make_tuple(arr[i][0], arr[i][1], i); //걸리는 기간, 받는 금액, 시작 날짜
				select(visited, result, theNumberOfSelect, num + 1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 0; i < n; i++) {
		vector<tuple<int, int, int>> result(i + 1);
		vector<bool> visited(n);
		//bool* visited = new bool[n];
		for (int j = 0; j < n; j++) {
			visited[i] = false;
		}
		select(visited, result, i + 1, 0);
		//delete visited;
	}
	int maxProfit = 0;
	for (int i = 0; i < profit.size(); i++) {
		if (profit[i] > maxProfit) maxProfit = profit[i];
	}
	cout << maxProfit;
	return 0;
}