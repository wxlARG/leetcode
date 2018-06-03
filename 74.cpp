#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int start_row=0, end_row=matrix.size()-1, target_row=-1;
    while(start_row<=end_row) {
        int mid_row = start_row + (end_row-start_row)/2;
        if(matrix[mid_row].size()==0) break;
        if(matrix[mid_row][0]==target) return true;
        else if(matrix[mid_row][0]>target) end_row=mid_row-1;
        else {
            start_row = mid_row+1;
            target_row = mid_row;
        }
    }
    if(target_row==-1) return false;
    int start_col=0, end_col=matrix[target_row].size()-1;
    while(start_col<=end_col) {
        int mid_col = start_col + (end_col-start_col)/2;
        if(matrix[target_row][mid_col]==target) return true;
        else if(matrix[target_row][mid_col]>target) end_col=mid_col-1;
        else start_col=mid_col+1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    cout << searchMatrix(matrix, 0) << endl;
}
