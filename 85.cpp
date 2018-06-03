#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int res=0;
    if(matrix.size()==0) return 0;
    vector<int> cache(matrix[0].size(), 0);
    cache.push_back(INT_MIN);
    vector<int> stack;
    for(int i=0; i<matrix.size(); ++i) {
        for(int j=0; j<matrix[i].size(); ++j) {
            if(matrix[i][j]=='0') cache[j]=0;
            else cache[j] += matrix[i][j]-'0';
        }
        int tmp_res=0;
        stack.clear();
        for(int j=0; j<cache.size(); ++j) {
            while(!stack.empty() && cache[stack.back()]>cache[j]) {
                int height=cache[stack.back()], len=-1;
                stack.pop_back();
                if(!stack.empty()) len=stack.back();
                tmp_res=max(tmp_res, height*(j-len-1));
            }
            stack.push_back(j);
        }
        res=max(res, tmp_res);
    }
    return res;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << maximalRectangle(matrix) << endl;
}
