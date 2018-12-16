#include"common.h"
using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int res=INT_MIN;
    int row=matrix.size(), col=matrix[0].size(), m=max(row, col), n=min(row, col);
    vector<vector<int>> sum(n, vector<int>(m, 0));
    for(int i=0; i<n; ++i) {
        vector<int> sum(m, 0);
        for(int x=i; x>=0; --x) {
            for(int j=0; j<m; ++j) sum[j]+=row<col? matrix[x][j]: matrix[j][x];
            set<int> cache={0};
            int total=0;
            for(int j=0; j<m; ++j) {
                total+=sum[j];
                auto it=cache.lower_bound(total-k);
                if(it!=cache.end()) res=max(res, total-*it);
                if(res==k) return res;
                cache.insert(total);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix = {
        {5,-4,-3,4},
        {-3,-4,4,5},
        {5,1,5,-4}
    };
    cout << maxSumSubmatrix(matrix, 10) << endl;
}
