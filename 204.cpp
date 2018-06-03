#include"common.h"
using namespace std;

int countPrimes(int n) {
    if(n<=2) return 0;
    vector<int> primes={2};
    for(int num=3, pos=2, target=pos*pos; num<n; ++num) {
        if(num>target) {
            ++pos;
            target=pos*pos;
        }
        int i=0;
        for(; i<primes.size() && primes[i]<=pos; ++i) if(num%primes[i]==0) break;
        if(i==primes.size() || primes[i]>pos) primes.push_back(num);
    }
    return primes.size();
}

int main() {
    cout << countPrimes(10) << endl;
    cout << countPrimes(200000) << endl;
}
