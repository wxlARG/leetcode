#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
#include"common.h"
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int num = 0;
    for(int i=0, j=n-1; i<=j; ++i, --j) {
        if(i==j) {
            res[i][i] = ++num;
            break;
        }
        for(int k=i; k<j; ++k) {
            res[i][k] = ++num;
        }
        for(int k=i; k<j; ++k) {
            res[k][j] = ++num;
        }
        for(int k=j; k>i; --k) {
            res[j][k] = ++num;
        }
        for(int k=j; k>i; --k) {
            res[k][i] = ++num;
        }
    }
    return res;
}

int main() {
    auto res = generateMatrix(3);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
