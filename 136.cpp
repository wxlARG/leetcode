#include"common.h"
using namespace std;

int singleNumber(vector<int>& nums) {
    int res=0;
    for(auto &v: nums) res ^= v;
    return res;
}

int main() {
    vector<int> nums ={2, 2, 1};
    cout << singleNumber(nums) << endl;
}
