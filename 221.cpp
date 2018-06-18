#include"common.h"
using namespace std;

int maximalSquare_solution1(vector<vector<char>>& matrix) {
    int res=0;
    if(matrix.size()==0) return res;
    vector<int> cache(matrix[0].size(), 0);
    stack<int> s;
    for(int i=0; i<matrix.size(); ++i) {
        for(int j=0; j<matrix[i].size(); ++j) cache[j]=(matrix[i][j]=='0'? 0: cache[j]+matrix[i][j]-'0');
        for(int j=0; j<cache.size(); ++j) {
            while(!s.empty() && cache[s.top()]>=cache[j]) {
                int height=cache[s.top()];
                s.pop();
                int l=min(j-1-(s.empty()? -1: s.top()), height);
                res=max(l*l, res);
            } 
            s.push(j);
        }
        while(!s.empty()) {
            int height=cache[s.top()];
            s.pop();
            int l=min((int)cache.size()-1-(s.empty()? -1: s.top()), height);
            res=max(l*l, res);
        }
    }
    return res;
}

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size()==0) return 0;
    vector<int> dp(matrix[0].size()+1, 0);
    int r=0;
    for(int i=0; i<matrix.size(); ++i) {
        int last=dp[0];
        for(int j=0; j<matrix[i].size(); ++j) {
            int tmp=dp[j+1];
            if(matrix[i][j]=='0') dp[j+1]=0;
            else dp[j+1]=min(dp[j+1], min(dp[j], last))+1;
            last=tmp; 
            r=max(r, dp[j+1]);
        }
    }
    return r*r;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << maximalSquare(matrix) << endl;
}
