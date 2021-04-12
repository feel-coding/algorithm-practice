#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int cnt = 0;
int k;
bool visited[10];
string result = "          ";
string str;
set<int> primeNumbers;

void makeNumber(int current) {
	if (current == k) {
		int number = stoi(result.substr(0, k));
		bool flag = true;
		for (int i = 2; i <= sqrt(number); i++) {
			if (number % i == 0) {
				flag = false;
				break;
			}
		}
		if (number == 1 || number == 0) flag = false;
		if (flag) {
			primeNumbers.insert(number);
		}
		return;
	}
	for (int i = 0; i < str.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[current] = str[i];
			makeNumber(current + 1);
			visited[i] = false;
		}
	}
}

int solution(string numbers) {
	str = numbers;
	int answer = 0;
	for (int i = 1; i <= numbers.size(); i++) {
		k = i;
		makeNumber(0);
	}
	return primeNumbers.size();
}