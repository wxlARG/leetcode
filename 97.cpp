#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool isInterleave_solution1(string s1, string s2, string s3) {
    if(s1.size()+s2.size() != s3.size()) return false;
    vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
    dp[0][0] = true;
    for(int i=0; i<=s1.size(); ++i) {
        for(int j=0; j<=s2.size(); ++j) {
            bool up = (i>0? dp[i-1][j] && s3[i+j-1]==s1[i-1]: false);
            bool left = (j>0? dp[i][j-1] && s3[i+j-1]==s2[j-1]: false);
            dp[i][j] = (dp[i][j]|up|left);
        }
    }
    return dp[s1.size()][s2.size()];
}

bool isInterleave(string s1, string s2, string s3) {
    if(s1.size()+s2.size() != s3.size()) return false;
    vector<bool> dp(s2.size()+1, false);
    for(int i=0; i<=s1.size(); ++i) {
        for(int j=0; j<=s2.size(); ++j) {
            bool up = (i>0? dp[j] && s3[i+j-1]==s1[i-1]: false);
            bool left = (j>0? dp[j-1] && s3[i+j-1]==s2[j-1]: false);
            if(i==0 && j==0) dp[j] = true;
            else dp[j] = (up|left);
        }
    }
    return dp.back();
}

int main() {
    cout << isInterleave("ac", "ab", "abac") << endl;
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}
