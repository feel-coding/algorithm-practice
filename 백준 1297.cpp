#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int diagonal, w, h;
	cin >> diagonal >> h >> w;
	double x = sqrt((double)(diagonal * diagonal) / (h * h + w * w));
	int width = floor(w * x);
	int height = floor(h * x);
	cout << height << " " << width;
	return 0;
}