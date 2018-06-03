#include"common.h"
using namespace std;

bool isHappy(int n) {
    unordered_set<int> cache;
    while(n!=1) {
        if(cache.find(n)!=cache.end()) return false;
        cache.insert(n);
        int nn = n;
        for(n=0; nn; nn/=10) n+=(nn%10)*(nn%10);
    }
    return true;
}

int main() {
    cout << isHappy(19) << endl;
}
