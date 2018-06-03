#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string longestPalindrome_solution1(string s) {
    string ss(2*s.size()+1, '#');
    for(int i=0; i<s.size(); ++i)
        ss[2*i+1] = s[i];
    vector<int> c(ss.size(), 0);
    c[1] = 2;
    int maxpos = 1, maxlen = 2;
    for(int i=2; i<ss.size(); ++i) {
        if(i+c[i-2]-(i-2)>=c[i-1]) {
            c[i] = c[i-1];
            for(int right=c[i-1]+1, left=2*i-right; left>=0 && right<=ss.size()-1 && ss[left] == ss[right]; --left, ++right)
                ++c[i];
        } else {
            c[i] = i+c[i-2]-(i-2);
        }
        if(c[i]-i+1 > maxlen) {
            maxpos = i;
            maxlen = c[i]-i+1;
        }
    }
    int start = (maxpos-maxlen+1+1)/2;
    return s.substr(start, maxlen-1);
}

string longestPalindrome_solution2(string s) {
    string res;
    bool c[1001][1001] = {0};
    for(int k=1; k<=s.size(); ++k) {
        for (int i=0, j=i+k-1; j<s.size(); ++i, ++j) {
            if(i == j) 
                c[i][j] = true;
            else {
                bool t = (i+1>=j-1 ? true: c[i+1][j-1]);
                c[i][j] = (s[i] == s[j] ? t : false);
            }
            if(c[i][j] && k>res.size())
                res = s.substr(i, k);
        }
    }
    return res;
}

int main() {
    cout << longestPalindrome("abghba") << endl;
}
