#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string intToRoman(int num) {
    char cache[4][2] = {
        {'I', 'V'},
        {'X', 'L'},
        {'C', 'D'},
        {'M', 0}
    };
    string res;
    for(int flag=0; num != 0; num/=10, ++flag) {
        char *p = cache[flag];
        char *next = cache[(flag==3)? flag: flag+1];
        int tmp = num%10;
        if(tmp>0 && tmp<4) res = res + string(tmp, p[0]);
        else if(tmp==4) res = res + p[1] + p[0];
        else if(tmp>4 && tmp<9) res = res + string(tmp-5, p[0]) + p[1];
        else if(tmp==9) res = res + next[0] + p[0];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << intToRoman(99) << endl;
}
