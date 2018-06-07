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
    int res=0;
    if(matrix.size()==0) return res;
    vector<int> height(matrix[0].size(), 0), square(matrix[0].size()+1, 0);
    for(int i=0; i<matrix.size(); ++i) {
        vector<int> len(matrix[0].size(), 0);
        for(int j=0; j<matrix[i].size(); ++j) {
            int val=matrix[i][j]-'0';
            height[j]=(val==0? val: height[j]+val);
            len[j]=(val==0? 0: (j==0? 1: len[j-1]+1));
        }
        for(int j=square.size()-1; j>=1; --j) {
            if(square[j-1] && square[j-1]<min(height[j-1], len[j-1])) square[j]=square[j-1]+1;
            else if(square[j-1]) square[j]=min(height[j-1], len[j-1]);
            else square[j]=min(1, min(height[j-1], len[j-1]));
            res = max(square[j]*square[j], res);
        }
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
    cout << maximalSquare(matrix) << endl;
}
