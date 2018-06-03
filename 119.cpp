#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1, 1);
    for(int i=3; i<=rowIndex+1; ++i) {
        int last=res[0];
        for(int j=1; j<=i-2; ++j) {
            int c=res[j];
            res[j] += last;
            last=c;
        }
    }
    return res;
}

int main() {
    auto res = getRow(4);
    for(auto &v: res) {
        cout << v << "\t";
    }
    cout << endl;
}
