#include"common.h"
using namespace std;

void moveZeroes_solution1(vector<int>& nums) {
    int cpos=0;
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]!=0) swap(nums[cpos++], nums[i]);
    }
}

void moveZeroes(vector<int>& nums) {
    int cpos=0;
    for(int i=0; i<nums.size(); ++i) {
        if(nums[i]!=0) {
            if(cpos!=i) nums[cpos]=nums[i];
            ++cpos;
        }
    }
    for(int i=cpos; i<nums.size(); ++i) nums[i]=0;
}

int main() {
    vector<int> nums={0,1,0,3,12};
    moveZeroes(nums);
    for(auto &v: nums) cout << v << "\t";
    cout << endl;
}
