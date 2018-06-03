#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

int climbStairs(int n) {
    int first=1, second=2;
    if(n==1) return first;
    for(int i=3; i<=n; ++i) {
        int t = first+second;
        first = second;
        second = t;
    }
    return second;
}

int main() {
    cout << climbStairs(2) << endl;
    cout << climbStairs(3) << endl;
}
