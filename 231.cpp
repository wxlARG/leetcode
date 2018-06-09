#include"common.h"
using namespace std;

bool isPowerOfTwo(int n) {
    if(n<0) return false;
    int count=0;
    for(; n!=0; n>>=1) {
        if(n&1!=0) ++count;
    }
    return count==1? true: false;
}

int main() {
    cout << isPowerOfTwo(1) << endl;
    cout << isPowerOfTwo(16) << endl;
    cout << isPowerOfTwo(218) << endl;
    cout << isPowerOfTwo(-16) << endl;
}
