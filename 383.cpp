#include"common.h"
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26, 0);
    for(auto c: magazine) ++count[c-'a'];
    for(auto c: ransomNote) {
        if(--count[c-'a']<0) return false;
    }
    return true;
}

int main() {
    cout << canConstruct("a", "b") << endl;
    cout << canConstruct("aa", "ab") << endl;
    cout << canConstruct("aa", "aab") << endl;
}
