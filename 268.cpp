#include"common.h"
using namespace std;

int missingNumber_solution1(vector<int>& nums) {
    for(int i=0; i<nums.size(); ++i) {
        while(nums[i]!=i && nums[i]<nums.size()) swap(nums[i], nums[nums[i]]);
    }
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]!=i) return i;
    }
    return nums.size();
}

int missingNumber(vector<int>& nums) {
    int sum=accumulate(nums.begin(), nums.end(), 0);
    return (nums.size()+1)*nums.size()/2-sum;
}

int main() {
    //vector<int> nums={9,6,4,2,3,5,7,0,1};
    vector<int> nums={2,0,1};
    cout << missingNumber(nums) << endl;
}
