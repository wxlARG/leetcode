#include"common.h"
using namespace std;

bool isPowerOfFour_solution1(int num) {
    if(num<1) return false;
    int maxi=1<<30;
    return maxi%num==0 && ((int)log2(num) & 1)==0;
}

bool isPowerOfFour(int num) {
    return (num-(num&-num)==0) && (num&0x55555555)!=0;
}

int main() {
    cout << isPowerOfFour(16) << endl;
    cout << isPowerOfFour(5) << endl;
}
