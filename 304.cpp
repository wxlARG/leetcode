#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

class NumMatrix {
    public:
        NumMatrix(vector<vector<int> > &matrix){
            if(matrix.size()!=0)
                sums.push_back(vector<int>(matrix[0].size()+1,0));
            for(int i=0; i<matrix.size(); ++i)
            {
                vector<int> tmp(1,0);
                for(int j=0; j<matrix[i].size(); ++j)
                {
                    int val = sums.back()[j+1]+tmp.back()-sums.back()[j]+matrix[i][j];
                    tmp.push_back(val);
                }
                sums.push_back(tmp);
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2) {
            int val = sums[row2+1][col2+1]-sums[row1][col2+1]-sums[row2+1][col1]+sums[row1][col1];
            return val;
        }
    private:
        vector<vector<int> > sums;
};

int main()
{
    int arr[][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    vector<vector<int> > matrix;

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
    {
        vector<int> tmp;
        for(int j=0; j<5; ++j)
            tmp.push_back(arr[i][j]);
        matrix.push_back(tmp);
    }

    NumMatrix numArray(matrix);
    cout << numArray.sumRegion(2, 1, 4, 3) << endl;
    cout << numArray.sumRegion(1, 1, 2, 2) << endl;
    cout << numArray.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}
