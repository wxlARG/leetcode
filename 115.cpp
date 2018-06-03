#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int numDistinct_solution1(string s, string t) {
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=s.size(); ++i) {
        for(int j=0; j<=t.size(); ++j) {
            dp[i][j] = dp[i-1][j];
            if(j>0 && s[i-1]==t[j-1]) dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[s.size()][t.size()];
}

int numDistinct(string s, string t) {
    vector<int> dp(t.size()+1, 0);
    dp[0]=1;
    for(int i=1; i<=s.size(); ++i) {   
        int c=dp[0];
        for(int j=1; j<=t.size(); ++j) {
            int tmp=dp[j];
            if(s[i-1]==t[j-1]) dp[j]+=c;
            c=tmp;
        }
    }
    return dp.back();
}

int main() {
    cout << numDistinct("rabbbit", "rabbit") << endl;
    cout << numDistinct("", "a") << endl;
}
