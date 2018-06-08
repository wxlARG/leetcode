#include"common.h"
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if(nums.size()==0) return res;
    int start=nums[0], last=start;
    for(int i=1; i<nums.size(); ++i) {
        if(nums[i]-last!=1) {
            string cache=to_string(start);
            if(start!=last) cache += "->"+to_string(last);
            res.push_back(cache);
            start=nums[i];
        }
        last=nums[i];
    }
    string cache=to_string(start);
    if(start!=last) cache += "->"+to_string(last);
    res.push_back(cache);
    return res;
}

int main() {
    vector<int> nums={0,2,3,4,6,8,9};
    auto res=summaryRanges(nums);
    for(auto& str: res) cout << str << endl;
}
