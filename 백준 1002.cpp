#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		if (x1 == x2 && y1 == y2 && r1 == r2/*같은 원*/)
			cout << -1 << '\n';
		else if ((x1 == x2 && y1 == y2 && r1 != r2)/*동심원*/ || distance < pow(r1 - r2, 2)/*외부*/ || pow(r1 + r2, 2) < distance/*내부*/)
			cout << 0 << '\n';
		else if (pow(r1 + r2, 2) == distance/*외접*/ || pow(r1 - r2, 2) == distance/*내접*/)
			cout << 1 << '\n';
		else
			cout << 2 << '\n';
	}
	return 0;
}
