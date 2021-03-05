#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int now, goal, iceUp, defrost, notIceUp;
	cin >> now >> goal >> iceUp >> defrost >> notIceUp;
	int seconds = 0;
	while (true) {
		if (now == goal) break;
		if (now >= 0) {
			seconds += notIceUp;
			now++;
		}
		else {
			seconds += iceUp;
			now++;
			if (now == 0) seconds += defrost;
		}
	}
	cout << seconds;
	return 0;
}