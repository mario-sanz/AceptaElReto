#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

struct tPoint {
	int x;
	int y;
};


double calculateDistance(tPoint p1, tPoint p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool belongsToCircle(tPoint center, tPoint point, int radius) {
	return calculateDistance(center, point) <= radius;
}


int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int radius;
	tPoint point;

	while(cin >> radius >> point.x >> point.y) {
		int circles = 0;
		tPoint center = {0, 0};

		while (true) {
			if (belongsToCircle(center, point, radius))
				circles++;
			if (radius == 1)
				break;

			if ((point.y - center.y == point.x - center.x) || (point.y - center.y == -point.x + center.x))
				break;
			else if ((point.y - center.y > point.x - center.x) && (point.y - center.y > -point.x + center.x))
				center.y += radius;
			else if ((point.y - center.y < point.x - center.x) && (point.y - center.y > -point.x + center.x))
				center.x += radius;
			else if ((point.y - center.y < point.x - center.x) && (point.y - center.y < -point.x + center.x))
				center.y -= radius;
			else 
				center.x -= radius;

			radius /= 2;
		}

		cout << circles << endl;
	}

	return 0;
}