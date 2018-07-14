#include"common.h"
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    vector<int> res={0, 0};
    int val=0;
    for(auto& v: nums) val^=v;
    val&=(~(val-1));
    for(auto& v: nums) {
        if(v & val) res[0]^=v;
        else res[1]^=v;
    }
    return res;
}

int main() {
    vector<int> nums={1,2,1,3,2,5};
    auto res=singleNumber(nums);
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
