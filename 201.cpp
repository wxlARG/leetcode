#include"common.h"
using namespace std;

int rangeBitwiseAnd_solution1(int m, int n) {
    int res=m;
    while(res) {
        unsigned int target=res, pos=0;
        for(; (target&1)==0; ++pos) target>>=1;
        ++target;
        target<<=pos;
        if(target<=(unsigned int)n) res &= target;
        else break;
    }
    return res;
}

int rangeBitwiseAnd(int m, int n) {
    int res=n;
    while(res>m) res &= (res-1);
    return res;
}

int main() {
    cout << rangeBitwiseAnd(0, 1) << endl;
    cout << rangeBitwiseAnd(2147483646, 2147483647) << endl;
}
