#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int height, width, customerNumber;
		cin >> height >> width >> customerNumber;
		int n = 1;
		int floor = 1;
		int room = 1;
		if (customerNumber % height == 0) room = customerNumber / height;
		else room = customerNumber / height + 1;
		if(customerNumber % height == 0) floor = customerNumber % height + height;
		else floor = customerNumber % height;
		cout << floor * 100 + room << '\n';
	}
	return 0;
}