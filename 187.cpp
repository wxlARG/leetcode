#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

vector<string> findRepeatedDnaSequences_solution1(string s) {
    vector<string> res;
    unordered_map<string, int> cache;
    for(int i=0; i<s.size(); ++i) {
        string tmp=s.substr(i, 10);
        if(++cache[tmp]==2) res.push_back(tmp);
    }
    return res;
}

int helper(char c) {
    if(c=='A') return 0;
    else if(c=='C') return 1;
    else if(c=='G') return 2;
    return 3;
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<int, int> cache;
    int tmp=0xffffffff;
    for(int i=0; i<s.size(); ++i) {
        tmp = ((tmp<<2) | helper(s[i])) & 0x000fffff;
        if(++cache[tmp]==2) res.push_back(s.substr(i-9, 10));
    }
    return res;
}

int main() {
    auto res = findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(auto &str: res) cout << str << endl;
}
