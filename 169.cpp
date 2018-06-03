#include"common.h"
using namespace std;

int majorityElement(vector<int>& nums) {
    int res=0, count=0;
    for(int &v: nums) {
        if(count==0) {
            res=v;
            ++count;
        } else if(res!=v) {
            --count;
        } else {
            ++count;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
}
