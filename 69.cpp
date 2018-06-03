#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

int mySqrt(int x) {
    int res = 0;
    int start=1, end=x;
    while(start<=end) {
        int mid = start+(end-start)/2;
        if(mid<=x/mid) {
            res = mid;
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return res;
}

int main() {
    cout << mySqrt(4) << endl;
    cout << mySqrt(8) << endl;
    cout << mySqrt(0) << endl;
    cout << mySqrt(2147395599) << endl;
}
