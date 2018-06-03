#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int numTrees(int n) {
    vector<int> cache(n+1, 0);
    cache[0]=cache[1]=1;
    for(int i=2; i<=n; ++i) {
        for(int j=i-1; j>=i/2; --j) {
            if(j==i-1-j) cache[i] += cache[j]*cache[i-1-j];
            else cache[i] += (cache[j]*cache[i-1-j])*2;
        }
    }
    return cache.back();
}

int main() {
    cout << numTrees(5) << endl;
}
