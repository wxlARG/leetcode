#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool isPalindrome(string s) {
    for(int start=0, end=s.size()-1; start<end;) {
        if(!isalpha(s[start]) && !isdigit(s[start])) {
            ++start;
            continue;
        } else if(!isalpha(s[end]) && !isdigit(s[end])) {
            --end;
            continue;
        }
        int sc = isupper(s[start])? s[start]-'A': s[start]-'a';
        int ec = isupper(s[end])? s[end]-'A': s[end]-'a';
        if(sc != ec) return false;
        ++start;
        --end;
    }
    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << isPalindrome("race a car") << endl;
    cout << isPalindrome("0P0") << endl;
}
