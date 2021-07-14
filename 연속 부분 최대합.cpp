#include <iostream>
#include <cmath>
using namespace std;

int arr[100005];

int getMaxSum(int start, int end) {
	if (start == end) return arr[start];
	int mid = (start + end) / 2;
	int leftMax = getMaxSum(start, mid);
	int rightMax = getMaxSum(mid + 1, end);
	int middleLeftMax = arr[mid];
	int middleRightMax = arr[mid + 1];
	int sum = 0;
	for (int i = mid; i >= start; i--) {
		sum += arr[i];
		if (sum > middleLeftMax) middleLeftMax = sum;
	}
	sum = 0;
	for (int i = mid + 1; i <= end; i++) {
		sum += arr[i];
		if (sum > middleRightMax) middleRightMax = sum;
	}
	return max(middleLeftMax + middleRightMax, max(leftMax, rightMax));
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << getMaxSum(0, n - 1);
	return 0;
}
