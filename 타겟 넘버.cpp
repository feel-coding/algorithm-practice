#include <string>
#include <vector>

using namespace std;

vector<int> copyNumbers;
int targetNumber;
int cnt = 0;

void getResult(int current, int result) {
	if (current == copyNumbers.size()) {
		if (result == targetNumber) {
			cnt++;
		}
		return;
	}
	getResult(current + 1, result - copyNumbers[current]);
	getResult(current + 1, result + copyNumbers[current]);
}

int solution(vector<int> numbers, int target) {
	copyNumbers = numbers;
	targetNumber = target;
	getResult(0, 0);
	return cnt;
}
