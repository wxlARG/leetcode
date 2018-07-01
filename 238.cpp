#include"common.h"
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1);
    for(int i=1, cur=nums.front(); i<nums.size(); cur*=nums[i++]) res[i]=cur;
    for(int i=nums.size()-2, cur=nums.back(); i>=0; cur*=nums[i--]) res[i]*=cur;
    return res;
}

int main() {
    vector<int> nums={1,2,3,4};
    auto res=productExceptSelf(nums);
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
