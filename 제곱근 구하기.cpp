#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int result = sqrt(n);
	if (result * result == n) cout << result;
	else cout << result + 1;
	return 0;
}
