#include"common.h"
using namespace std;

int bulbSwitch(int n) {
    if(n<=1) return n;
    int res=0;
    for(int i=1; i*i<=n; ++i) ++res;
    return res;
}

int main() {
    cout << bulbSwitch(3) << endl;
}
