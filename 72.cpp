#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

int minDistance(string word1, string word2) {
    vector<int> dp(word2.size()+1, 0);
    for(int j=0; j<word2.size(); ++j) dp[j+1] = j+1;
    for(int i=0; i<word1.size(); ++i) {
        int c;
        for(int j=0; j<dp.size(); ++j) {
            int tmp = dp[j];
            if(j==0) {
                dp[j] = i+1;
            } else {
                int del = dp[j]+1;
                int ins = dp[j-1]+1;
                int rep = c + (word1[i]==word2[j-1]? 0: 1);
                dp[j] = min(del, min(ins, rep));
            }
            c = tmp;
        }
    }
    return dp.back();
}

int main() {
    cout << minDistance("abc", "bba") << endl;
    cout << minDistance("ab", "a") << endl;
    cout << minDistance("a", "ab") << endl;
}
