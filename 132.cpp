#include"common.h"
using namespace std;

int minCut(string s) {
    vector<int> dp(s.size(), 0);
    dp[0]=1;
    unordered_map<int, vector<int>> cache;
    cache[0]={0};
    for(int i=1; i<s.size(); ++i) {
        cache[i]={i};
        int m=dp[i-1]+1;
        for(auto &v: cache[i-1]) {
            if(v==i-1 && s[v]==s[i]) {
                cache[i].push_back(v);
                m=min(m, (v>0? dp[v-1]: 0)+1);
            } 
            if(v>0 && s[v-1]==s[i]) {
                cache[i].push_back(v-1);
                m=min(m, (v>1? dp[v-2]: 0)+1);
            }
        }
        dp[i]=m;
    }
    return dp.back()-1;
}

int main() {
    cout << minCut("aab") << endl;
    cout << minCut("baababa") << endl;
}
