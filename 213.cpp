#include"common.h"
using namespace std;

int rob(vector<int>& nums) {
    if(nums.size()==0) return 0;
    pair<int, int> round1={0, nums[0]}, round2={0, 0};
    for(int i=1; i<nums.size(); ++i) {
        if(i<nums.size()-1) {
            int tmp=max(round1.first+nums[i], round1.second);
            round1.first=round1.second;
            round1.second=tmp;
        }
        int tmp=max(round2.first+nums[i], round2.second);
        round2.first=round2.second;
        round2.second=tmp;
    }
    return max(round1.second, round2.second);
}

int main() {
    vector<int> nums={1,2,3,1};
    //vector<int> nums={2,3,2};
    cout << rob(nums) << endl;
}
