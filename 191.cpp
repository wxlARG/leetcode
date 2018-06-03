#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

int hammingWeight(uint32_t n) {
    int res=0;
    for(; n; n>>=1) {
        if(n&1) ++res;
    }
    return res;
}

int main() {
    cout << hammingWeight(11) << endl;
    cout << hammingWeight(128) << endl;
}
