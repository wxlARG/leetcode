#include"common.h"
using namespace std;

int helper(int n, bool d) {
    if(n==1) return 1;
    if(d || (n&1)!=0) return 2*helper(n>>1, !d);
    return 2*helper(n>>1, !d)-1;
}

int lastRemaining_solution1(int n) {
    return helper(n, true);
}

int lastRemaining(int n) {
    int start=1, end=n, step=1;
    bool forward=true;
    while(start<end) {
        int next_step=step*2;
        if(forward) {
            if((end-start)%next_step==0) end-=step;
            start+=step;
        } else {
            if((end-start)%next_step==0) start+=step;
            end-=step;
        }
        step=next_step;
        forward = !forward;
    }
    return start;
}

int main() {
    cout << lastRemaining(9) << endl;
}
