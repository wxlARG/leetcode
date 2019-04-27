#include"common.h"
using namespace std;

int longestSubstring_solution1(string s, int k) {
    vector<queue<int>> cache(26);
    vector<int> index(26);
    int res=0;
    for(int i=0; i<index.size(); ++i) index[i]=i;
    auto cmp = [&](int a, int b) {
        return cache[a].size()<cache[b].size() || (!cache[a].empty() && cache[a].size()==cache[b].size() && cache[a].front()<cache[b].front());
    };
    for(int i=0; i<s.size(); ++i) {
        if(cache[s[i]-'a'].size()==k) cache[s[i]-'a'].pop();
        cache[s[i]-'a'].push(i);
        sort(index.begin(), index.end(), cmp);
        int pos=0;
        for(auto idx: index) {
            if(cache[idx].empty()) continue;
            if(cache[idx].size()<k) pos=max(pos, cache[idx].back()+1);
            else if(cache[idx].front()<pos) pos=max(pos, cache[idx].back()+1);
        }
        if(pos<=i) res=max(res, i-pos+1);
    }
    return res;
}

int longestSubstring(string s, int k) {
    int res=0;
    for(int i=1; i<=26; ++i) {
        int start=0, char_num=0, less_num=0;
        vector<int> count(26, 0);
        for(int pos=0; pos<s.size(); ++pos) {
            if(count[s[pos]-'a']==0) ++less_num;
            if(count[s[pos]-'a'] == 0) ++char_num;
            ++count[s[pos]-'a'];
            if(count[s[pos]-'a']==k) --less_num;
            while(char_num>i) {
                if(count[s[start]-'a']==k) ++less_num;
                if(count[s[start]-'a']==1) {
                    --char_num;
                    --less_num;
                }
                --count[s[start++]-'a'];
            }
            if(char_num==i && less_num==0) res=max(res, pos-start+1);
        }
    }
    return res;
}

int main() {
    cout << longestSubstring("aaabb", 3) << endl;
    cout << longestSubstring("bbaaacbd", 3) << endl;
}
