#include"common.h"
using namespace std;

char findTheDifference(string s, string t) {
    vector<int> cache(26, 0);
    for(auto c: s) ++cache[c-'a'];
    for(auto c: t) {
        if(cache[c-'a']--<=0) return c;
    }
    return 0;
}

int main() {
    cout << findTheDifference("abcd", "abcde") << endl;
}
