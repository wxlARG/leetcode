#include"common.h"
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    srand(time(NULL));
    --k;
    int start=0, end=nums.size()-1;
    while(start<=end) {
        swap(nums[end], nums[start+rand() % (end-start+1)]);
        int pos=start; 
        for(int i=start; i<end; ++i) {
            if(nums[i]>nums[end]) swap(nums[pos++], nums[i]);
        }
        swap(nums[pos], nums[end]);
        if(pos==k) return nums[pos];
        else if(pos>k) end=pos-1;
        else start=pos+1;
    }
    return -1;
}

int main() {
    vector<int> nums={3,2,1,5,6,4};
    cout << findKthLargest(nums, 2) << endl;
}
