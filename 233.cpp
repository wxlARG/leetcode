#include"common.h"
using namespace std;

int countDigitOne(int n) {
    int res=0;
    if(n<=0) return res;
    int max_count=1, exp=1;
    for(int tn=n; tn>=10; tn/=10) {
        ++max_count;
        exp*=10;
    }
    while(n) {
        int p=n/exp;
        if(p>1) res+=exp+p*(max_count-1)*(exp/10);
        else res+=(n%exp+1)+(max_count-1)*(exp/10);
        n=n%exp;
        while(n<exp) {
            exp/=10;
            --max_count;
        }
    }
    return res;
}

int main() {
    cout << countDigitOne(13) << endl;
    cout << countDigitOne(617) << endl;
    cout << countDigitOne(101) << endl;
}
