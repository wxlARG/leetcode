#include"common.h"
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> res;
    if(nums1.empty() || nums2.empty()) return res;
    auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
        return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    pq.push({0, 0});
    while(!pq.empty() && res.size()<k) {
        auto pos=pq.top();
        pq.pop();
        res.push_back({nums1[pos.first], nums2[pos.second]});
        if(pos.second==0 && pos.first+1<nums1.size()) pq.push({pos.first+1, 0});
        if(pos.second+1<nums2.size()) pq.push({pos.first, pos.second+1});
    }
    return res;
}

int main() {
    vector<int> nums1={1,7,11};
    vector<int> nums2={2,4,6};
    auto res=kSmallestPairs(nums1, nums2, 3);
    for(auto& v: res) {
        cout << v.first << "\t" << v.second << endl;
    }
}
