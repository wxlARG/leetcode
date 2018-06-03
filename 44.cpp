#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isMatch(string s, string p) {
    vector<bool> dp(p.size()+1, 0);
    dp[0] = true;
    for(int i=0; i<p.size() && p[i]=='*'; ++i)
        dp[i+1] = true;
    for(int i=0; i<s.size(); ++i) {
        bool last = dp[0];
        for(int j=0; j<=p.size(); ++j) {
            bool v = dp[j];
            dp[j] = false;
            if(j>0 && (v || dp[j-1]) && p[j-1]=='*') dp[j]=true;
            if(j>0 && last && (p[j-1]=='?' || p[j-1] == '*' || s[i]==p[j-1])) dp[j]=true;
            last = v;
        }
    }
    return dp.back();
}

int main() {
    cout << isMatch("ab", "?*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("a", "a*") << endl;
}
