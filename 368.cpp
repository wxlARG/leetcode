#include"common.h"
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    sort(nums.begin(), nums.end());
    vector<pair<int, int>> cache(nums.size());
    pair<int, int> maxi={0, -1};
    for(int i=0; i<nums.size(); ++i) {
        cache[i]={1, -1};
        for(int j=0; j<i; ++j) {
            if(nums[i]%nums[j]==0 && cache[i].first<=cache[j].first) cache[i]={cache[j].first+1, j};
        }
        if(maxi.first<cache[i].first) maxi={cache[i].first, i};
    }
    auto cur=maxi;
    while(cur.second!=-1) {
        res.push_back(nums[cur.second]);
        cur=cache[cur.second];
    }
    return res;
}

int main() {
    vector<int> nums = {1,2,4,8};
    auto res=largestDivisibleSubset(nums);
    for(auto v: res) cout << v << "\t";
    cout << endl;
}
