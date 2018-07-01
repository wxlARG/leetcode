#include"common.h"
using namespace std;

vector<int> helper(vector<int>& nums, vector<char>& symbols, int start, int end) {
    if(start==end) return {nums[start]};
    vector<int> res;
    for(int i=start; i<=end-1; ++i) {
        auto left=helper(nums, symbols, start, i);
        auto right=helper(nums, symbols, i+1, end);
        for(auto& l: left) {
            for(auto& r: right) {
                if(symbols[i]=='+') res.push_back(l+r);
                else if(symbols[i]=='-') res.push_back(l-r);
                else res.push_back(l*r);
            }
        }
    }
    return res;
}

vector<int> diffWaysToCompute_solution1(string input) {
    vector<int> nums;
    vector<char> symbols;
    for(int i=0; i<input.size(); ) {
        if(input[i]>='0' && input[i]<='9') {
            int num=0;
            for(; input[i]>='0' && input[i]<='9'; ++i) num = num*10+input[i]-'0';
            nums.push_back(num);
        } else {
            symbols.push_back(input[i]);
            ++i;
        }
    }
    return helper(nums, symbols, 0, nums.size()-1);
}

vector<int> diffWaysToCompute(string input) {
    vector<int> nums;
    vector<char> symbols;
    for(int i=0; i<input.size(); ) {
        if(input[i]>='0' && input[i]<='9') {
            int num=0;
            for(; input[i]>='0' && input[i]<='9'; ++i) num = num*10+input[i]-'0';
            nums.push_back(num);
        } else {
            symbols.push_back(input[i]);
            ++i;
        }
    }
    vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>()));
    for(int len=1; len<=nums.size(); ++len) {
        for(int start=0; start<=nums.size()-len; ++start) {
            int end=start+len-1;
            if(start==end) {
                dp[start][end].push_back(nums[start]);
            } else {
                for(int k=start; k<end; ++k) {
                    for(auto& l: dp[start][k]) {
                        for(auto& r: dp[k+1][end]) {
                            if(symbols[k]=='+') dp[start][end].push_back(l+r);
                            else if(symbols[k]=='-') dp[start][end].push_back(l-r);
                            else dp[start][end].push_back(l*r);
                        }
                    }
                }
            }
        }
    }
    return dp[0][nums.size()-1];
}

int main() {
    //auto res=diffWaysToCompute("2*3-4*5");
    auto res=diffWaysToCompute("2-1-1");
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
