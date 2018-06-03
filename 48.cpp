#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size()-1;
    for(int i=0; i<(n/2+1); ++i) {
        for(int j=0; j<(n+1)/2; ++j) {
            int val = matrix[i][j];
            int cur_i=i, cur_j=j;
            for(int i=0; i<4; ++i) {
                int next_i = cur_j;
                int next_j = n-cur_i;
                int tmp = matrix[next_i][next_j];
                matrix[next_i][next_j]=val;
                val = tmp;
                cur_i=next_i;
                cur_j=next_j;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    rotate(matrix);
    for(auto &vec: matrix) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
