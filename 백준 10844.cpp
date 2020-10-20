#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* zero = new int[n];
	int* one = new int[n];
	int* two = new int[n];
	int*  three= new int[n];
	int* four = new int[n];
	int* five = new int[n];
	int* six = new int[n];
	int* seven = new int[n];
	int* eight = new int[n];
	int* nine = new int[n];
	zero[0] = 0;
	one[0] = 1;
	two[0] = 1;
	three[0] = 1;
	four[0] = 1;
	five[0] = 1;
	six[0] = 1;
	seven[0] = 1;
	eight[0] = 1;
	nine[0] = 1;
	for (int i = 1; i < n; i++) {
		zero[i] = one[i - 1];
		one[i] = (zero[i - 1] + two[i - 1]) % 1000000000;
		two[i] = (one[i - 1] + three[i - 1]) % 1000000000;
		three[i] = (two[i - 1] + four[i - 1]) % 1000000000;
		four[i] = (three[i - 1] + five[i - 1]) % 1000000000;
		five[i] = (four[i - 1] + six[i - 1]) % 1000000000;
		six[i] = (five[i - 1] + seven[i - 1]) % 1000000000;
		seven[i] = (six[i - 1] + eight[i - 1]) % 1000000000;
		eight[i] = (seven[i - 1] + nine[i - 1]) % 1000000000;
		nine[i] = eight[i - 1];
	}
	int sum = 0;
	sum = zero[n - 1];
	sum = (sum + one[n - 1]) % 1000000000;
	sum = (sum + two[n - 1]) % 1000000000;
	sum = (sum + three[n - 1]) % 1000000000;
	sum = (sum + four[n - 1]) % 1000000000;
	sum = (sum + five[n - 1]) % 1000000000;
	sum = (sum + six[n - 1]) % 1000000000;
	sum = (sum + seven[n - 1]) % 1000000000;
	sum = (sum + eight[n - 1]) % 1000000000;
	sum = (sum + nine[n - 1]) % 1000000000;
	cout << sum;
	return 0;
}