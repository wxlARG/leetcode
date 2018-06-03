#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool isScramble(string s1, string s2) {
    if(s1.size()!=s2.size()) return false;
    vector<vector<vector<bool>>> dp(s1.size(), vector<vector<bool>>(s1.size(), vector<bool>(s1.size(), false)));
    for(int k=0; k<s1.size(); ++k) {
        for(int i=0; i<s1.size()-k; ++i) {
            for(int j=0; j<s2.size()-k; ++j) {
                if(k==0) {
                    dp[k][i][j] = (s1[i]==s2[j]);
                } else {
                    for(int p=0; p<k; ++p) {
                        dp[k][i][j] = ((dp[p][i][j+k-p] && dp[k-p-1][i+p+1][j]) || (dp[p][i][j] && dp[k-p-1][i+p+1][j+p+1]));
                        if(dp[k][i][j]) break;
                    }
                }
            }
        }
    }
    return dp[s1.size()-1][0][0];
}

int main() {
    cout << isScramble("great", "rgeat") << endl;
    cout << isScramble("great", "garet") << endl;
    cout << isScramble("great", "garte") << endl;
}
