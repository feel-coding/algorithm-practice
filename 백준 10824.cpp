#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	long long ab = stoll(a + b);
	long long cd = stoll(c + d);
	cout << ab + cd;
	return 0;
}
