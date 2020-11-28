#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
using namespace std;

bool cmp(tuple<int, string, int>& p1, tuple<int, string, int>& p2) {
	if (get<0>(p1) == get<0>(p2)) {
		return (get<2>(p1) < get<2>(p2));
	}
	else return (get<0>(p1) < get<0>(p2));
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	tuple<int, string, int>* arr = new tuple<int, string, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> get<0>(arr[i]);
		cin >> get<1>(arr[i]);
		get<2>(arr[i]) = i;
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << "\n";
	}
	return 0;
}