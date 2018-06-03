#include"common.h"
using namespace std;

string shortestPalindrome_solution1(string s) {
    if(s.empty()) return "";
    string ns;
    for(auto &ch: s) {
        ns.push_back(ch);
        ns.push_back('#');
    }
    ns.pop_back();
    vector<int> cache(ns.size(), 0);
    int maxi=0, end_pos=0;
    for(int i=1; i<ns.size(); ++i) {
        if(i<=end_pos) cache[i]=min(end_pos-i, cache[2*maxi-i]);
        if(i+cache[i]<end_pos) continue;
        for(int r=max(end_pos+1, i+1), l=2*i-r; l>=0 && r<ns.size() && ns[l]==ns[r]; ++r, --l) {
            cache[i]=r-i;
            if(end_pos<r) maxi=i;
            end_pos=max(end_pos, r);
        }
    }
    for(int i=0; i<cache.size(); ++i) {
        if(i-cache[i]==0) end_pos=(i+cache[i])/2;
    }
    string res=s.substr(end_pos+1);
    reverse(res.begin(), res.end());
    return res+s;
}

string shortestPalindrome(string s) {
    if(s.empty()) return "";
    string revs=s;
    reverse(revs.begin(), revs.end());
    string needle=s+"#"+revs;
    vector<int> next(needle.size(), -1);
    for(int i=1, j=-1; i<needle.size(); ++i) {
        while(j!=-1 && needle[i]!=needle[j+1]) j=next[j];
        if(needle[i]==needle[j+1]) ++j;
        next[i]=j;
    }
    revs=s.substr(next.back()+1);
    reverse(revs.begin(), revs.end());
    return revs+s;
}

int main() {
    cout << shortestPalindrome("aaacecaaa") << endl;
    cout << shortestPalindrome("aacecaaa") << endl;
    cout << shortestPalindrome("abcd") << endl;
}
