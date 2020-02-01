#include"common.h"
using namespace std;

int longestPalindrome(string s) {
    int res=0;
    unordered_set<char> cache;
    for(auto c: s) {
        if(cache.count(c) == 1) {
            res+=2;
            cache.erase(c);
        } else {
            cache.insert(c);
        }
    }
    if(!cache.empty()) res+=1;
    return res;
}

int main() {
    cout << longestPalindrome("abccccdd") << endl;
}
