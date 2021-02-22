#include <iostream>
#include <stack>
using namespace std;

int main() {
	static int arr[500005];
	static int answer[500005];
	stack<int> stack;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	stack.push(1);
	for (int i = 2; i <= n; i++) {
		if (!stack.empty()) {
			if (arr[stack.top()] > arr[i]) {
				answer[i] = stack.top();
				stack.push(i);
			}
			else {
				while (!stack.empty()) {
					if (arr[stack.top()] > arr[i]) {
						break;
					}
					else {
						stack.pop();
					}
				}
				if (stack.empty()) {
					answer[i] = 0;
				}
				else answer[i] = stack.top();
				stack.push(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}