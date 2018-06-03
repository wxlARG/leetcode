#include"common.h"
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordCache;
    for(auto &str: wordDict) wordCache.insert(str);
    vector<bool> dp(s.size(), false);
    for(int i=0; i<s.size(); ++i) {
        for(int j=-1; j<i; ++j) {
            dp[i]=(j==-1? true: dp[j]) && wordCache.find(s.substr(j+1, i-j))!=wordCache.end();
            if(dp[i]) break;
        }
    }
    return dp.back();
}

int main() {
    vector<string> wordDict={"leet", "code"};
    cout << wordBreak("leetcode", wordDict) << endl;
}
