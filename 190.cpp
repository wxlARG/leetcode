#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

uint32_t reverseBits_solution1(uint32_t n) {
    uint32_t res=0;
    for(int i=0; i<32; ++i) {
        if((n & (1<<i))==0) continue;
        res |= (1<<(31-i));
    }
    return res;
}

uint32_t reverseBits(uint32_t n) {
    for(int start=0, end=31; start<end; ++start, --end) {
        bool tmp=(n&(1<<start));
        if(n&(1<<end)) n |= (1<<start);
        else n &= ~(1<<start);
        if(tmp) n |= (1<<end);
        else n &= ~(1<<end);
    }
    return n;
}

int main() {
    cout << reverseBits(43261596) << endl;
}
