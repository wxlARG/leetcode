#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int strStr_solution1(string haystack, string needle) {
    for(int i=0; i<haystack.size(); ++i) {
        int j=0;
        for(int k=i; k<haystack.size() && j<needle.size(); ++j, ++k) {
            if(haystack[k] != needle[j]) break;
        }
        if(j == needle.size()) return i;
    }
    return (needle.size()==0? 0: -1);
}

int strStr(string haystack, string needle) {
    if(needle.size()==0) return 0;
    vector<int> next(needle.size(), -1);
    int j=-1;
    for(int i=1; i<needle.size(); ++i) {
        while(j!=-1 && needle[j+1]!=needle[i]) j=next[j];
        if(needle[j+1]==needle[i]) ++j;
        next[i]=j;
    }

    j=-1;
    for(int i=0; i<haystack.size(); ++i) {
        while(j!=-1 && needle[j+1]!=haystack[i]) j=next[j];
        if(needle[j+1]==haystack[i]) ++j;
        if(j==int(needle.size())-1) return i-needle.size()+1;
    }
    return -1;
}

int main() {
    cout << strStr("babaaa", "aaa") << endl;
}
