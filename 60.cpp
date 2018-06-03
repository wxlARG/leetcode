#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
#include"common.h"
using namespace std;

string getPermutation(int n, int k) {
    string res;
    vector<int> f(n, 1);
    for(int i=1; i<n; ++i) {
        f[i] = f[i-1]*i;
    }
    vector<bool> cache(n, false);
    for(int i=1; i<=n; ++i) {
        for(int j=1, p=0; j<=n; ++j) {
            if(cache[j]) continue;
            if(++p == (k-1)/f.back()+1) {
                cache[j] = true;
                res.push_back(j + '0');
                k = (k-1)%f.back() + 1;
            }
        }
        f.pop_back();
    }
    return res;
}

int main() {
    cout << getPermutation(3, 5) << endl;
}
