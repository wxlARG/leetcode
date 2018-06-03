#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

bool isNumber(string s) {
    bool dot=false, eflag=false, isnum=false;
    int start=0, end=s.size()-1;
    while(start<=end && s[start]==' ') ++start;
    while(start<=end && s[end]==' ') --end;
    if(start>end) return false;
    for(int i=start; i<=end; ++i) {
        if(s[i]== '.') {
            if(dot || eflag) return false;
            if(i==end && !isnum) return false;
            dot = true;
        } else if(s[i]=='e') {
            if(eflag || i==end || !isnum) return false;
            eflag = true;
        } else if(s[i]=='+' || s[i]=='-') {
            if(!(i==start || (i!=end && s[i-1]=='e'))) return false;
        } else if(isdigit(s[i])) {
            isnum = true;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isNumber(".1") << endl;
    cout << isNumber("0") << endl;
    cout << isNumber(" 0.1") << endl;
    cout << isNumber("abc") << endl;
    cout << isNumber("1 a") << endl;
    cout << isNumber("2e10") << endl;
    cout << isNumber(".") << endl;
    cout << isNumber("3.") << endl;
    cout << isNumber("-1.") << endl;
    cout << isNumber("+.8") << endl;
    cout << isNumber("+ 1") << endl;
    cout << isNumber(" ") << endl;
    cout << isNumber(" 005047e+6") << endl;
    cout << isNumber("4e+") << endl;
}
