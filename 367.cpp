#include"common.h"
using namespace std;

bool isPerfectSquare_solution1(int num) {
    for(int64_t start=1, end=1<<16; start<=end; ) {
        int64_t mid=start+(end-start)/2;
        if(mid*mid==num) return true;
        if(mid*mid>num) end=mid-1;
        else start=mid+1;
    }
    return false;
}

bool isPerfectSquare(int num) {
    int r=num;
    while(r*r>num) r=(r+num/r)/2;
    return r*r==num;
}

int main() {
    cout << isPerfectSquare(16) << endl;
    cout << isPerfectSquare(14) << endl;
}
