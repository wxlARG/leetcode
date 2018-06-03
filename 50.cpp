#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

double myPow_solution1(double x, int n) {
    if(n==0) return 1;
    if(n==INT_MIN) return 1/x*myPow_solution1(x, n+1);
    if(n<0) return myPow_solution1(1/x, -n);
    auto v = myPow_solution1(x, n>>1);
    if(n & 1) return x*v*v;
    return v*v;
}

double myPow(double x, int n) {
    double res=1;
    if(n==0) return 1;
    if(n<0) {
        x = 1/x;
        if(n==INT_MIN) {
            res = 1/x;
            n += 1;
        }
        n = -n;
    }
    while(n) {
        if(n & 1) {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    cout << myPow(2, 3) << endl;
    cout << myPow(2, 20) << endl;
    cout << myPow(34.00515, -3) << endl;
    cout << myPow(1, -2147483648) << endl;
}
