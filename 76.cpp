#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

string minWindow_solution1(string s, string t) {
    string res;
    unordered_map<char, list<int>> cache;
    for(auto &c: t) {
        if(cache.find(c)==cache.end()) {
            cache[c] = list<int>(1, -1);
        } else {
            cache[c].push_back(-1);
        }
    }
    int min=-1, total=0;
    for(int i=0; i<s.size(); ++i) {
        auto it = cache.find(s[i]);
        if(it==cache.end()) continue;
        if(min==-1) min=i;
        int front_val = it->second.front();
        it->second.pop_front();
        it->second.push_back(i);
        ++total;
        if(front_val!=-1) {
            --total;
            if(min==front_val) {
                for(int j=min+1; j<=i; ++j) {
                    auto iit = cache.find(s[j]);
                    if(iit!=cache.end() && (iit->second.front()==-1 || iit->second.front()==j)) {
                        min = j;
                        break;
                    }
                }
            }
        }
        if(total == t.size()) {
            if(res.size()==0 || res.size()>i-min+1) {
                res = s.substr(min, i-min+1);
            }
        }
    }
    return res;
}

string minWindow(string s, string t) {
    string res;
    vector<int> cache(128, 0);
    for(auto c: t) ++cache[c];
    int start=0, end=0, len=INT_MAX, counter=t.size();
    while(end<s.size()) {
        if(cache[s[end++]]-->0) --counter;
        while(counter==0) {
            if(len>end-start) {
                len = end-start;
                res=s.substr(start, len);
            }
            if(cache[s[start++]]++==0) ++counter;
        }
    }
    return res;
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("bba", "ab") << endl;
    cout << minWindow("aaabbaaba", "abbb") << endl;
}
