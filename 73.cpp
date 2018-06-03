#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool first_row=false;
    for(int i=0; i<matrix.size(); ++i) {
        for(int j=0; j<matrix[0].size(); ++j) {
            if(matrix[i][j]==0) {
                if(i==0) first_row = true;
                else matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for(int i=matrix.size()-1; i>=0; --i) {
        for(int j=matrix[0].size()-1; j>=0; --j) {
            if(i==0 && first_row) matrix[0][j] = 0;
            else if(i!=0 && (matrix[i][0]==0 || matrix[0][j]==0)) matrix[i][j] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 0},
        {1, 0 ,2},
        {6, 2, 1}
    };
    setZeroes(matrix);
    for(auto &vec: matrix) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
