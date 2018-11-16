#include"common.h"
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size()>nums2.size()) return intersect(nums2, nums1);
    unordered_map<int, int> dict;
    vector<int> res;
    for(auto v: nums1) ++dict[v];
    for(auto v: nums2) {
        if(dict[v]-->0) res.push_back(v);
    }
    return res;
}

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    auto res = intersect(nums1, nums2);
    for(auto v: res) cout << v << "\t";
    cout << endl;
}
