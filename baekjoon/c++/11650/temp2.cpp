#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

bool cmp(const Point& a, const Point& b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

    sort(points.begin(), points.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << "\n";
    }
    return 0;
}
// vector 사용이 시간을 늘리지 않았나 추측:
