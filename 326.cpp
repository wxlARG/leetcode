#include"common.h"
using namespace std;

bool isPowerOfThree_solution1(int n) {
    if(n<=0) return false;
    if(n>=43046721) {
        if(n%43046721!=0) return false;
        n/=43046721;
    }
    if(n>=6561) {
        if(n%6561!=0) return false;
        n/=6561;
    }
    if(n>=81) {
        if(n%81!=0) return false;
        n/=81;
    }
    return n==1 || n==3 || n==9 || n==27;
}

bool isPowerOfThree(int n) {
    if(n<=0) return false;
    return 1162261467%n==0;
}

int main() {
    cout << isPowerOfThree(27) << endl;
}
