#include"common.h"
using namespace std;

int integerReplacement_solution1(int n) {
    if(n<2) return 0;
    if(n&1) return min(integerReplacement_solution1(n/2), integerReplacement_solution1(n/2+1))+2;
    return integerReplacement_solution1(n/2)+1;
}

int integerReplacement(int n) {
    int res=0;
    while(n>1) {
        if((n&1)==0) {
            ++res;
            n>>=1;
        } else if(n==3 || (n&0x02)==0) {
            res+=2;
            n>>=1;
        } else {
            res+=2;
            n=(n>>1)+1;
        }
    }
    return res;
}

int main() {
    cout << integerReplacement(8) << endl;
}
