#include"common.h"
using namespace std;

int firstUniqChar(string s) {
    vector<int> cache(26, 0);
    for(auto c: s) ++cache[c-'a'];
    for(int i=0; i<s.size(); ++i) {
        if(cache[s[i]-'a']==1) return i;
    }
    return -1;
}

int main() {
    cout << firstUniqChar("leetcode") << endl;
}
