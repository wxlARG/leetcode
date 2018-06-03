#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

vector<int> grayCode(int n) {
    vector<int> res = {0};
    if(n==0) return res;
    int size = 1<<n;
    for(int b=1; res.size()!=size; b<<=1) {
        for(int i=res.size()-1; i>=0; --i) res.push_back(res[i] | b);
    }
    return res;
}

int main() {
    auto res = grayCode(3);
    for(auto &v: res) {
        cout << v << "\t";
    }
    cout << endl;
}
