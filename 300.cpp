#include"common.h"
using namespace std;

int lengthOfLIS_solution1(vector<int>& nums) {
    int res=0;
    map<int, int> cache;
    for(auto &v: nums) {
        auto it=cache.lower_bound(v);
        if(cache.empty() || it==cache.begin()) {
            res=max(res, 1);
            cache[v]=1;
        } else {
            --it;
            res=max(res, it->second+1);
            cache[v]=it->second+1;
        }
        for(auto cur=cache.find(v); ; cur=cache.find(v)) {
            auto it=cur, next=++it;
            if(next==cache.end()) break;
            if(next->second<=cur->second) cache.erase(next);
            else break;
        }
    }
    return res;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> cache;
    for(auto &v: nums) {
        auto it=lower_bound(cache.begin(), cache.end(), v);
        if(it==cache.end()) cache.push_back(v);
        else *it=v;
    }
    return cache.size();
}

int main() {
    //vector<int> nums = {10,9,2,5,3,7,101,18};
    vector<int> nums = {1,4,5,6,2,3,5,6};
    cout << lengthOfLIS(nums) << endl;
}
