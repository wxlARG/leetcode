#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestValidParentheses_solution1(string s) {
    int res=0;
    vector<int> c(s.size(), -1);
    int zeropos=-1, endpos=-1;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == '(') {
            c[++endpos]=0;
            zeropos = endpos;
        } else {
            if(zeropos == -1) {
                endpos = -1;
                continue;
            }
            int sum = 0;
            c[zeropos] = 2;
            for(; endpos>=0; --endpos) {
                if(c[endpos] == 0) break;
                sum += c[endpos];
            }
            zeropos = endpos;
            c[++endpos] = sum;
            res = max(res, sum);
        }
    }
    return res;
}

int longestValidParentheses(string s) {
    vector<int> dp(s.size(), 0);
    int res = 0;
    for(int i=1; i<s.size(); ++i) {
        if(s[i]=='(') continue;
        if(s[i-1]=='(') {
            dp[i] = (i>1? dp[i-2]: 0)+2;
        } else if(s[i-1]==')' && s[i-1-dp[i-1]]=='(') {
            int pos = i-1-dp[i-1];
            dp[i] = dp[i-1]+2+(pos>0? dp[pos-1]: 0);
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    cout << longestValidParentheses(")()())()()(") << endl;
    cout << longestValidParentheses("()") << endl;
    cout << longestValidParentheses("()(())") << endl;
}
