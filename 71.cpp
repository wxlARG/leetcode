#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

string simplifyPath(string path) {
    string res;
    vector<string> cache;
    for(int i=0; i<path.size(); ++i) {
        if(path[i]=='/') continue;
        string t;
        for(int j=i; j<path.size() && path[j]!='/'; ++j) {
            t.push_back(path[j]);
        }
        i += t.size();
        if(t==".") {
            continue;
        } else if(t=="..") {
            if(cache.size()!=0) cache.pop_back();
        } else {
            cache.push_back(t);
        }
    }
    if(cache.size()==0) return "/";
    for(auto &s: cache) {
        res += "/" + s;
    }
    return res;
}

int main() {
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    cout << simplifyPath("/../") << endl;
}
