#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, vector<int>> m;
    for(auto i=0; i<nums.size(); ++i)
        if(m[nums[i]].size() < 2)
            m[nums[i]].push_back(i);

    for(auto &i : nums) {
        if(i == target - i && m[i].size() == 2) {
            res = m[i];
        } else if(m.find(target - i) != m.end() && i != target - i) {
            res.push_back(m[i][0]);
            res.push_back(m[target-i][0]);
            break;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3, 3};
    auto res = twoSum(nums, 6);
    for(auto &i: res)
        cout << i << "\t";
    cout << endl;
}
