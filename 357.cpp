#include"common.h"
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if(n==0) return 1;
    int res=10, cur=9, next=10;
    for(int i=2; i<=n; ++i) {
        cur*=(--next);
        res+=cur;
    }
    return res;
}

int main() {
    cout << countNumbersWithUniqueDigits(2) << endl;
    cout << countNumbersWithUniqueDigits(3) << endl;
}
