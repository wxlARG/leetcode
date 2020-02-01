#include"common.h"
using namespace std;

int splitArray(vector<int>& nums, int m) {
    vector<int64_t> cache(nums.size(), INT_MAX);
    for(int i=0; i<m; ++i) {
        vector<int64_t> tmp(nums.size(), 0);
        int64_t pos=-1, sum=0;
        for(int j=0; j<nums.size(); ++j) {
            sum+=nums[j];
            int64_t tmp_max=max(pos==-1? 0: cache[pos], sum);
            for(int k=pos+1; k<j; ++k) {
                int nv=max(cache[pos+1], sum-nums[k]);
                if(tmp_max<nv) break;
                tmp_max=nv;
                sum-=nums[k];
                ++pos;
            }
            tmp[j]=tmp_max;
        }
        cache.swap(tmp);
    }
    return cache.back();
}

int main() {
    //vector<int> nums={7,2,5,10,8};
    vector<int> nums={1,2147483647};
    cout << splitArray(nums, 2) << endl;
}
