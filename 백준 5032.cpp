#include <iostream>
using namespace std;

int main() {
	int e, f, c;
	cin >> e >> f >> c;
	int answer = 0;
	int bottle = e + f;
	int newBottle;
	while (true) {
		newBottle = bottle / c;
		answer += newBottle;
		bottle = bottle % c;
		bottle += newBottle;
		if (bottle < c) break;
	}
	cout << answer;
	return 0;
}