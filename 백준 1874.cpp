#include <iostream>
#include <stack>
using namespace std;

int main() {
	int arr[100005];
	char operators[200005];
	stack<int> stack;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack.push(1);
	int num = 1; // num������ ���ִ�
	int index = 1; // index�� �� ����
	operators[0] = '+';
	for (int i = 0; i < n; i++) {
		if (arr[i] > num) {
			while (true) {
				stack.push(++num);
				operators[index++] = '+';
				if (num == arr[i]) {
					stack.pop();
					operators[index++] = '-';
					break;
				}
			}
		}
		else if (!stack.empty() && stack.top() == arr[i]) {
			stack.pop();
			operators[index++] = '-';
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < index; i++) {
		cout << operators[i] << '\n';
	}
	return 0;
}