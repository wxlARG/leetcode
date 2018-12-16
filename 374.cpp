#include"common.h"
using namespace std;

static int pick=6;

int guess(int num) {
    return pick==num? 0: (num>pick? -1: 1);
}

int guessNumber(int n) {
    int start=1, end=n;
    while(start<end) {
        int mid=start+(end-start)/2;
        if(guess(mid)==0) return mid;
        if(guess(mid)>0) start=mid+1;
        else end=mid-1;
    }
    return start;
}

int main() {
    cout << guessNumber(10) << endl;
}
