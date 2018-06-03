#include"common.h"
using namespace std;

int maxProduct(vector<int>& nums) {
    int cur_max=1, cur_min=1, res=INT_MIN;
    for(auto &n: nums) {
        int c_max=cur_max*n, c_min=cur_min*n;
        cur_max=max(max(c_max, c_min), n);
        cur_min=min(min(c_max, c_min), n);
        res=max(res, cur_max);
    }
    return res;
}

int main() {
    vector<int> nums={2,3,-2,4};
    cout << maxProduct(nums) << endl;
}
