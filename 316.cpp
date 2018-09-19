#include"common.h"
using namespace std;

string removeDuplicateLetters_solution1(string s) {
    vector<deque<int>> cache(26);
    string res;
    for(int i=0; i<s.size(); ++i) cache[s[i]-'a'].push_back(i);
    while(1) {
        bool bk=true;
        vector<int> tmp(26, -1);
        int val=INT_MAX;
        for(int i=cache.size()-1; i>=0; --i) {
            if(cache[i].empty()) continue;
            bk=false;
            val=min(val, cache[i].back());
            tmp[i]=val;
        }
        if(bk) break;
        for(int i=0; i<26; ++i) {
            if(!cache[i].empty() && cache[i].front()<=tmp[i]) {
                res+=i+'a';
                break;
            }
        }
        int pos=cache[res.back()-'a'].front();
        cache[res.back()-'a'].clear();
        for(int i=0; i<26; ++i) {
            while(!cache[i].empty() && cache[i].front()<pos) cache[i].pop_front();
        }
    }
    return res;
}

string removeDuplicateLetters(string s) {
    string res;
    vector<int> count(26, 0);
    vector<bool> visited(26, false);
    for(int i=0; i<s.size(); ++i) ++count[s[i]-'a'];
    for(int i=0; i<s.size(); ++i) {
        --count[s[i]-'a'];
        if(visited[s[i]-'a']) continue;
        while(!res.empty() && res.back()>s[i] && count[res.back()-'a']!=0) {
            visited[res.back()-'a']=false;
            res.pop_back();
        }
        res.push_back(s[i]);
        visited[s[i]-'a']=true;
    }
    return res;
}

int main() {
    cout << removeDuplicateLetters("bcabc") << endl;
    cout << removeDuplicateLetters("cbacdcbc") << endl;
    cout << removeDuplicateLetters("abacb") << endl;
    cout << removeDuplicateLetters("bba") << endl;
}
