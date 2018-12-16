#include"common.h"
using namespace std;

bool canMeasureWater_solution1(int x, int y, int z) {
    if(x>y) return canMeasureWater_solution1(y, x, z);
    if(z>y) z-=x;
    if(z>y) return false;
    if(z==0) return true;
    if(x==0) return y==z;
    int next=y;
    unordered_set<int> cache;
    while(next>=z && cache.count(next)==0) {
        cache.insert(next);
        if((next-z)%x==0) return true;
        next=y-(x-(next%x));
    }
    return false;
}

int gcd(int x, int y) {
    while(x) {
        int tmp=x;
        x=y%x;
        y=tmp;
    }
    return y;
}

bool canMeasureWater(int x, int y, int z) {
    if(z==0) return true;
    if(z>x+y) return false;
    if(x==0) return y==z;
    return z%gcd(x,y) == 0;
}

int main() {
    cout << canMeasureWater(3, 5, 4) << endl;
    cout << canMeasureWater(2, 6, 5) << endl;
    cout << canMeasureWater(1, 2, 3) << endl;
    cout << canMeasureWater(0, 0, 1) << endl;
}
