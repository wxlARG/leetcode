#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

string addBinary(string a, string b) {
    string res(max(a.size(), b.size())+1, '0');
    int carry=0, pos=res.size()-1;
    for(int i=a.size()-1, j=b.size()-1; i>=0 || j>=0; --i, --j, --pos) {
        int aa = (i>=0? a[i]-'0': 0);
        int bb = (j>=0? b[j]-'0': 0);
        int v = aa+bb+carry;
        res[pos] = v%2+'0';
        carry = v/2;
    }
    if(carry!=0) {
        res[pos]=carry+'0';
        return res;
    }
    return res.substr(1);
}

int main() {
    cout << addBinary("10", "1") << endl;
}
