#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isMatch_solution1(string s, string p) {
    vector<vector<bool>> m(s.size()+1, vector<bool>(p.size()+1, false));
    m[0][0] = true;
    for(int i=0; i<=s.size(); ++i) {
        for(int j=1; j<=p.size(); ++j) {
            if(i>0 && j>1 && m[i-1][j] && p[j-1]== '*' && (p[j-2]=='.' || p[j-2]==s[i-1]))
                m[i][j] = true;
            if(i>0 && m[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.'))
                m[i][j] = true;
            if(j>1 && m[i][j-2] && p[j-1] == '*')
                m[i][j] = true;
        }
    }
    return m[s.size()][p.size()];
}

bool isMatch_solution2(string s, string p) {
    vector<bool> m(p.size()+1, false);
    for(int i=0; i<=s.size(); ++i) {
        bool last = m[0];
        m[0] = (i==0 ? true : false);
        for(int j=1; j<=p.size(); ++j) {
            bool cur = m[j];
            m[j] = false;
            if(i>0 && j>1 && cur && p[j-1]== '*' && (p[j-2]=='.' || p[j-2]==s[i-1]))
                m[j] = true;
            if(i>0 && last && (s[i-1]==p[j-1] || p[j-1]=='.'))
                m[j] = true;
            if(j>1 && m[j-2] && p[j-1] == '*')
                m[j] = true;
            last = cur;
        }
    }
    return m[p.size()];
}

int main() {
    cout << isMatch_solution1("aa","aa") << endl;
}
