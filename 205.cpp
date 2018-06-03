#include"common.h"
using namespace std;

bool isIsomorphic(string s, string t) {
    vector<char> cachest(256, 0),  cachets(256, 0);
    for(int i=0; i<s.size(); ++i) {
        if(cachest[s[i]]==0 && cachets[t[i]]==0) {
            cachest[s[i]]=t[i];
            cachets[t[i]]=s[i];
        } else if(cachest[s[i]]==t[i] && cachets[t[i]]==s[i]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isIsomorphic("egg", "add") << endl;
    cout << isIsomorphic("foo", "bar") << endl;
    cout << isIsomorphic("paper", "title") << endl;
    cout << isIsomorphic("ab", "aa") << endl;
}
