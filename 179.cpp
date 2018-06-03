#include"common.h"
using namespace std;

string largestNumber(vector<int>& nums) {
    string res;
    vector<string> cache;
    for(auto &v: nums) cache.push_back(to_string(v));
    auto f = [](const string& s1, const string& s2) -> bool {
        return s1+s2>s2+s1;
    };
    sort(cache.begin(), cache.end(), f);
    for(auto &s: cache) {
        if(s=="0" && res.empty()) continue;
        res += s;
    }
    return res.empty()? "0": res;
}

int main() {
    vector<int> nums = {0,0,0,0,0,0,0};
    cout << largestNumber(nums) << endl;
}
