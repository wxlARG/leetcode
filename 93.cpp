#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void helper(string& s, int start, vector<string>& res, vector<string>& cache) {
    if(start==s.size() && cache.size()==4) {
        string s;
        for(int i=0; i<cache.size(); ++i) s += cache[i]+".";
        s.pop_back();
        res.push_back(s);
        return;
    } else if(cache.size()==4) {
        return;
    }
    for(int i=start; i<s.size() && i<start+3; ++i) {
        if(s[start]=='0' && i>start) break;
        string str = s.substr(start, i-start+1);
        if(stoi(str)>255) break;
        cache.push_back(str);
        helper(s, i+1, res, cache);
        cache.pop_back();
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res, cache;
    helper(s, 0, res, cache);
    return res;
}

int main() {
    auto res = restoreIpAddresses("010010");
    for(auto &s: res) {
        cout << s << endl;
    }
}
