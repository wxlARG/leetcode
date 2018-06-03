#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int numDecodings(string s) {
    int cur=0, prev=0;
    for(int i=0; i<s.size(); ++i) {
        int nc = 0;
        if(s[i]>='1' && s[i]<='9') nc = (cur==0? 1: cur);
        else if (s[i]=='0' && i>0 && s[i-1]>='1' && s[i-1]<='2') nc = (prev==0? 1: prev);
        else return 0;
        if(s[i]!='0' && i>0 && ((s[i-1]>'0' && s[i-1]<'2') || (s[i-1]=='2' && s[i]>='1' && s[i]<='6'))) nc += (prev==0? 1: prev);
        prev = cur;
        cur = nc;
    }
    return cur;
}

int main() {
    cout << numDecodings("123412") << endl;
    cout << numDecodings("0") << endl;
    cout << numDecodings("10") << endl;
    cout << numDecodings("100") << endl;
    cout << numDecodings("103") << endl;
}
