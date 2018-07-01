#include"common.h"
using namespace std;

int countDigitOne_solution1(int n) {
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

int countDigitOne(int n) {
    long long res=0, exp=10;
    if(n<=0) return res;
    for(int tn=n; tn; tn/=10, exp*=10) {
        if(tn%10==0) res += n/exp*exp/10;
        else if(tn%10==1) res += n/exp*exp/10+n%(exp/10)+1;
        else res += (n/exp+1)*exp/10;
    }
    return res;
}

int main() {
    cout << countDigitOne(13) << endl;
    cout << countDigitOne(617) << endl;
    cout << countDigitOne(101) << endl;
}
