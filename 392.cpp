#include"common.h"
using namespace std;

bool isSubsequence(string s, string t) {
    int i=0;
    for(auto c: t) {
        if(s[i]==c) {
            ++i;
            if(i==s.size()) break;
        }
    }
    return i==s.size();
}

int main() {
    cout << isSubsequence("abc", "ahbgdc") << endl;
}
