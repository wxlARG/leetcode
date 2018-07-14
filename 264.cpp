#include"common.h"
using namespace std;

int nthUglyNumber(int n) {
    vector<int> cache={1};
    int i2=0, i3=0, i5=0;
    for(int i=1; i<n; ++i) {
        int m=min(min(2*cache[i2], 3*cache[i3]), 5*cache[i5]);
        cache.push_back(m);
        if(2*cache[i2]==m) ++i2;
        if(3*cache[i3]==m) ++i3;
        if(5*cache[i5]==m) ++i5;
    }
    return cache.back();
}

int main() {
    cout << nthUglyNumber(1) << endl;
    cout << nthUglyNumber(10) << endl;
    cout << nthUglyNumber(11) << endl;
}
