#include"common.h"
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    deque<int> maxq;
    for(int i=0; i<nums.size(); ++i) {
        if(!maxq.empty() && i-maxq.front()>=k) maxq.pop_front();
        while(!maxq.empty() && nums[maxq.back()]<=nums[i]) maxq.pop_back();
        maxq.push_back(i);
        if(i>=k-1) res.push_back(nums[maxq.front()]);
    }
    return res;
}

int main() {
    vector<int> nums={1,3,1,2,0,5};
    auto res=maxSlidingWindow(nums, 3);
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
