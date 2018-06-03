#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
#include"common.h"
using namespace std;

int lengthOfLastWord(string s) {
    int res = 0;
    int i=s.size()-1;
    while(s[i]==' ') {
        --i;
    }
    for(; i>=0 && s[i]!=' '; --i) {
        ++res;
    }
    return res;
}

int main() {
    cout << lengthOfLastWord("Hello World") << endl;
    cout << lengthOfLastWord("a ") << endl;
}
