#include"common.h"
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size()) return false;
    vector<int> map(26, 0);
    for(auto& c: s) ++map[c-'a'];
    for(auto& c: t) {
        if(--map[c-'a']<0) return false;
    }
    return true;
}

int main() {
    cout << isAnagram("anagram", "nagaram") << endl;
    cout << isAnagram("rat", "car") << endl;
}
