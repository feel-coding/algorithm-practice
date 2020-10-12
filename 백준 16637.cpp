#include <iostream>
#include <vector>
#include <string>
using namespace std;
//16637번
vector<int> result;
vector<char> operators;
vector<int> operands;
int n;
long long maxResult = -2147483647;

void combination(vector<bool> visited, vector<int> endResult, int k, int num) {
	if (k == num) {
		vector<char> realOperators;
		vector<int> realOperands;
		realOperands.push_back(operands[0]);
		for (int i = 1; i < operands.size(); i++) {
			bool isIn = false;
			for (int j = 0; j < endResult.size(); j++) {
				if (endResult[j] == i) {
					isIn = true;
					break;
				}
			}
			if (isIn) {
				realOperators.push_back(operators[i - 1]);
				realOperands.push_back(result[i]);
				i++;
			}
			else {
				realOperators.push_back(operators[i - 1]);
				realOperands.push_back(operands[i]);
			}
		}
	
		int calculate = realOperands[0];
		for (int i = 0; i < realOperators.size(); i++) {
			switch (realOperators[i]) {
			case '*':
				calculate *= realOperands[i + 1];
				break;
			case '-':
				calculate -= realOperands[i + 1];
				break;
			case '+':
				calculate += realOperands[i + 1];
				break;
			}
		}
		if (calculate > maxResult) maxResult = calculate;
		return;
	}
	for (int i = 1; i < n / 2; i++) {
		if (num == 0) {
			if (!visited[i]) {
				visited[i] = true;
				endResult[num] = i;
				combination(visited, endResult, k, num + 1);
				visited[i] = false;
			}
		}
		else {
			if (!visited[i] && endResult[num - 1] < i - 1) {
				visited[i] = true;
				endResult[num] = i;
				combination(visited, endResult, k, num + 1);
				visited[i] = false;
			}
		}
	}
}


int main() {
	cin >> n;
	int operandIndex = 0;
	int operatorIndex = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			operands.push_back(s[i] - '0');
		}
		else {
			operators.push_back(s[i]);
		}
	}
	result = vector<int>(n / 2);
	for (int i = 0; i < n / 2; i++) {
		switch (operators[i]) {
		case '*':
			result[i] = operands[i] * operands[i + 1];
			break;
		case '+':
			result[i] = operands[i] + operands[i + 1];
			break;
		case '-':
			result[i] = operands[i] - operands[i + 1];
			break;
		}
	}
	if (n == 1) {
		cout << operands[0];
	}
	else {
		for (int i = 0; i <= (n - 3) / 2; i++) {
			vector<int> endResult(i);
			vector<bool> visited(n / 2);
			combination(visited, endResult, i, 0);
		}
		cout << maxResult;
	}
	
	return 0;
}