#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int n;
vector<int> v;
set<int> answer;
int number;
bool flag;

void permutation(int num, vector<int> result) {
	if (num == n) {
		number = 0;
		flag = true;
		for (int i = 0; i < n; i++) {
			number += (result[i] * pow(10, n - 1 - i));
		}
		answer.insert(number);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		result[num] = i;
		number = 0;
		flag = true;
		for (int j = 0; j <= num; j++) {
			number += (result[j] * pow(10, num - j));
		}
		if (number == 1)
			flag = false;
		for (int j = 2; j <= sqrt(number); j++) {
			if (number % j == 0) {
				flag = false;
				break;
			}
		}
	
		if(flag)
			permutation(num + 1, result);
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	v = vector<int>(n);
	permutation(0, vector<int>(n));
	for (set<int>::iterator iter = answer.begin(); iter != answer.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}