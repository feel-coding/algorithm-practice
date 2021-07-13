#include <iostream>
using namespace std;

long long getResult(long long n, long long m) {
	if (m == 0) return 1;
	if (m == 1) return n;
	if (m % 2 == 0) {
		long long temp = getResult(n, m / 2);
		return temp * temp % 10007;
	}
	else {
		return n * getResult(n, m - 1) % 10007;
	}
}

int main() {
	long long n, m;
	cin >> n >> m;
	cout << getResult(n, m);
	return 0;
}
