#include"common.h"
using namespace std;

void helper(vector<string>& res, string cache, string& num, int start, pair<int, int> nums, int target) {
    if(start==num.size()) {
        if(!cache.empty() && (nums.first+nums.second)==target) res.push_back(cache);
        return;
    }
    long long v=0;
    for(int i=start; i<num.size(); ++i) {
        if(num[start]=='0' && i>start) break;
        v = v*10+num[i]-'0';
        if(v>INT_MAX) break;
        string tm=num.substr(start, i-start+1);
        if(start==0) {
            helper(res, tm, num, i+1, {0, v}, target);
        } else {
            helper(res, cache+"+"+tm, num, i+1, {nums.first+nums.second, v}, target);
            helper(res, cache+"-"+tm, num, i+1, {nums.first+nums.second, -v}, target);
            helper(res, cache+"*"+tm, num, i+1, {nums.first, nums.second*v}, target);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> res;
    helper(res, "", num, 0, {0, 0}, target);
    return res;
}

int main() {
    auto res=addOperators("123456789", 45);
    for(auto& str: res) cout << str << endl;
}
