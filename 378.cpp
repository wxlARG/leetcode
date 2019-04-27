#include"common.h"
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
        return matrix[a.first][a.second]>matrix[b.first][b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pq.push({0,0});
    int res;
    while(!pq.empty() && k>0) {
        auto top=pq.top();
        pq.pop();
        --k;
        res=matrix[top.first][top.second];
        if(top.second==0 && top.first<matrix.size()-1) pq.push({top.first+1, 0});
        if(top.second<matrix.size()-1) pq.push({top.first, top.second+1});
    }
    return res;
}

int main() {
    vector<vector<int>> nums = {
        { 1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    cout << kthSmallest(nums, 8) << endl;
}
