#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include"common.h"
using namespace std;

void helper(string &s, int start, int end, vector<string>& cache, vector<vector<string>>& res) {
    if(start>end) {
        res.push_back(cache);
        return;
    }
    for(int i=start; i<=end; ++i) {
        bool is_palindrome=true;
        for(int b=start, e=i; b<e && is_palindrome; ++b, --e) if(s[b]!=s[e]) is_palindrome=false;
        if(is_palindrome) {
            cache.push_back(s.substr(start, i-start+1));
            helper(s, i+1, end, cache, res);
            cache.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cache;
    helper(s, 0, s.size()-1, cache, res);
    return res;
}

int main() {
    auto res = partition("aab");
    for(auto &v: res) {
        for(auto &s: v) cout << s << "\t";
        cout << endl;
    }
}
