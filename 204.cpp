#include"common.h"
using namespace std;

int countPrimes_solution1(int n) {
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

int countPrimes(int n) {
    int res=0;
    vector<bool> cache(n, true);
    cache[0]=cache[1]=false;
    for(int i=2; i<n; ++i) {
        if(cache[i]) {
            ++res;
            for(int count=2; count*i<n; ++count) cache[count*i]=false;
        }
    }
    return res;
}

int main() {
    cout << countPrimes(10) << endl;
    cout << countPrimes(200000) << endl;
}
