#include"common.h"
using namespace std;

int findNthDigit(int n) {
    int64_t base=1, step=9, num=1;
    while(n>step*num) {
        n-=step*num;
        base*=10;
        step*=10;
        ++num;
    }
    --n;
    auto num_str=to_string(base+n/num);
    return num_str[n%num]-'0';
}

int main() {
    cout << findNthDigit(3) << endl;
    cout << findNthDigit(11) << endl;
}
