#include"common.h"
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int row=matrix.size()+1;
        if(matrix.size()==0) return;
        int col=matrix[0].size()+1;
        sums=vector<vector<int>>(row, vector<int>(col, 0));
        for(int i=1; i<row; ++i) {
            for(int j=1; j<col; ++j) sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i-1][j-1];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];
    }
private:
    vector<vector<int>> sums;
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix obj(matrix);
    cout << obj.sumRegion(2, 1, 4, 3) << endl;
    cout << obj.sumRegion(1, 1, 2, 2) << endl;
}
