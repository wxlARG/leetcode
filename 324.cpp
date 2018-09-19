#include"common.h"
using namespace std;

//#define get(i) (i>=nums.size()/2? (i-nums.size()/2)*2: 2*i+1)
#define get(i) ((2*i+1)%(nums.size()|1))
void helper(vector<int>& nums, int start, int end) {
    if(start>=end) return;
    int pos=start;
    for(int i=start; i<end; ++i) {
        if(nums[get(i)]>nums[get(end)]) {
            swap(nums[get(pos)], nums[get(i)]);
            ++pos;
        }
    }
    swap(nums[get(pos)], nums[get(end)]);
    helper(nums, start, pos-1);
    helper(nums, pos+1, end);
}

void wiggleSort_solution1(vector<int>& nums) {
    helper(nums, 0, nums.size()-1);
}

void wiggleSort(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end());
    int mid=*(nums.begin()+nums.size()/2);
    int pos=0;
    for(int i=0; i<nums.size(); ++i) {
        if(nums[get(i)]>mid) {
            swap(nums[get(pos)], nums[get(i)]);
            ++pos;
        }
    }
    pos=nums.size()-1;
    for(int i=nums.size()-1; i>=0; --i) {
        if(nums[get(i)]<mid) {
            swap(nums[get(pos)], nums[get(i)]);
            --pos;
        }
    }
}

int main() {
    //vector<int> nums={1, 5, 1, 1, 6, 4};
    vector<int> nums={5,4,5,5,5,6,6,6};
    wiggleSort(nums);
    for(auto& v: nums) cout << v << "\t";
    cout << endl;
}
