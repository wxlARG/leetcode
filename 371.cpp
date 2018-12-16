#include"common.h"
using namespace std;

#define geti(num, pos) (((uint32_t)num & (1<<pos))>>pos)
#define seti(num, pos) (num |= (1<<pos))

int getSum_solution1(int a, int b) {
    int carry=0, res=0;
    for(int i=0; i<32; ++i) {
        int x=geti(a, i), y=geti(b, i);
        if(x^y^carry) {
            seti(res, i);
            if(x&y&carry) carry=1;
            else carry=0;
        } else {
            if(x|y|carry) carry=1;
            else carry=0;
        }
    }
    return res;
}

int getSum(int a, int b) {
    while(b!=0) {
        int tmp = a;
        a^=b;
        b=(tmp&b)<<1;
    }
    return a;
}

int main() {
    cout << getSum(1, 2) << endl;
    cout << getSum(-2, 3) << endl;
    cout << getSum(2, 3) << endl;
}
