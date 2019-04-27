#include"common.h"
using namespace std;

string helper(string& s, int& pos) {
    string res;
    while(pos<s.size() && s[pos]!=']') {
        if(!isdigit(s[pos])) {
            res+=s[pos++];
        } else {
            int num=0;
            for(; isdigit(s[pos]); ++pos) num=num*10+s[pos]-'0';
            ++pos;
            auto str=helper(s, pos);
            ++pos;
            for(int i=0; i<num; ++i) res+=str;
        }
    }
    return res;
}

string decodeString(string s) {
    int pos=0;
    return helper(s, pos);
}

int main() {
    cout << decodeString("2[abc]3[cd]ef") << endl;
}
