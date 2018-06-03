#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if(matrix.size()==0) {
        return res;
    }
    for(int i=0, j=0, i_end=matrix.size()-1, j_end=matrix[0].size()-1; i<=i_end && j<=j_end; ++i, ++j, --i_end, --j_end) {
        if(i == i_end) {
            for(int k=j; k<=j_end; ++k) {
                res.push_back(matrix[i][k]);
            }
            continue;
        }
        if(j==j_end) {
            for(int k=i; k<=i_end; ++k) {
                res.push_back(matrix[k][j]);
            }
            continue;
        }
        for(int k=j; k<j_end; ++k) {
            res.push_back(matrix[i][k]);
        }
        for(int k=i; k<i_end; ++k) {
            res.push_back(matrix[k][j_end]);
        }
        for(int k=j_end; k>j; --k) {
            res.push_back(matrix[i_end][k]);
        }
        for(int k=i_end; k>i; --k) {
            res.push_back(matrix[k][j]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto res = spiralOrder(matrix);
    for(auto &v: res) {
        cout << v << "\t";
    }
    cout << endl;
}
