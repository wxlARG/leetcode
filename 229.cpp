#include"common.h"
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    vector<pair<int, int>> cache(2, {0, 0});
    for(auto& num: nums) {
        if(cache[0].first==num) ++cache[0].second;
        else if(cache[1].first==num) ++cache[1].second;
        else if(cache[0].second==0) cache[0]={num, 1};
        else if(cache[1].second==0) cache[1]={num, 1};
        else --cache[0].second, --cache[1].second;
    }
    if(cache[0].second!=0 && count(nums.begin(), nums.end(), cache[0].first)>nums.size()/3) res.push_back(cache[0].first);
    if(cache[1].second!=0 && count(nums.begin(), nums.end(), cache[1].first)>nums.size()/3) res.push_back(cache[1].first);
    return res;
}

int main() {
    vector<int> nums={1,1,1,3,3,2,2,2};
    auto res=majorityElement(nums);
    for(auto& num: res) cout << num << "\t";
    cout << endl;
}
