#include"common.h"
using namespace std;

void reverse(string &s, int start, int end) {
    if(start>=s.size()) return;
    while(start<=end) swap(s[start++], s[end--]);
}

void reverseWords(string &s) {
    int pos=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]==' ' && (pos==0 || i+1==s.size() || s[i+1]==' ')) continue;
        s[pos++]=s[i];
    }
    s.erase(pos);
    int start=0, p=start;
    while(p<s.size()) {
        while(p<s.size() && s[p]!=' ') ++p;
        reverse(s, start, p-1);
        start=p=p+1;
    }
    reverse(s, start, p);
    reverse(s, 0, s.size()-1);
}

int main() {
    string s="the sky is blue";
    //string s="  a  b    ";
    reverseWords(s);
    cout << s << endl;
}
