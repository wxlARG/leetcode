#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int divide(int dividend, int divisor) {
    int res=0, flag=1;
    if(dividend>0) {
        dividend = -dividend;
        flag = -flag;
    }
    if(divisor>0) {
        divisor = -divisor;
        flag = -flag;
    }
    while(dividend<=divisor) {
        int v=1, s=divisor;
        while(s>=dividend && s>(INT_MIN>>1)) {
            v<<=1;
            s<<=1;
        }
        if(s<dividend) {
            res -= (v>>1);
            dividend -= (s>>1);
        } else {
            res -= v;
            dividend -= s;
        }
    }
    return (flag==-1? res: res==INT_MIN? INT_MAX: -res);
}

int main() {
    cout << divide(INT_MIN, 1) << endl;
}
