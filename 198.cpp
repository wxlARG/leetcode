#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

int rob(vector<int>& nums) {
    int first=0, second=0;
    for(auto &num: nums) {
        int val=max(second, first+num);
        first=second;
        second=val;
    }
    return second;
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << rob(nums) << endl;
}
