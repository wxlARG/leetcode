#include"common.h"
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b) {
    while(b!=0) {
        int c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int maxPoints(vector<Point>& points) {
    if(points.size()<=1) return points.size();
    map<pair<int, int>, int> cache;
    int res=0;
    for(int i=0; i<points.size(); ++i) {
        cache.clear();
        int dup=1;
        for(int j=i+1; j<points.size(); ++j) {
            if(points[i].x==points[j].x && points[i].y==points[j].y) {
                ++dup;
                continue;
            }
            int dx=points[i].x-points[j].x, dy=points[i].y-points[j].y;
            pair<int, int> slot = {dx/gcd(dx, dy), dy/gcd(dx, dy)};
            ++cache[slot];
        }
        res = max(res, dup);
        for(auto &kv: cache) res=max(res, kv.second+dup);
    }
    return res;
}

int main() {
	vector<Point> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << maxPoints(points) << endl;
}
