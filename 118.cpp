#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for(int i=1; i<=numRows; ++i) {
        vector<int> cache(i, 1);
        for(int j=1; j<=int(cache.size())-2; ++j) {
            cache[j] = res.back().at(j-1)+res.back().at(j);
        }
        res.push_back(cache);
    }
    return res;
}

int main() {
    auto res = generate(5);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
