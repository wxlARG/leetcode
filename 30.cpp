#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<int> findSubstring_solution1(string s, vector<string>& words) {
    int len = words[0].size();
    vector<int> res;
    unordered_map<string, vector<list<int>>> m;
    vector<int> start(len, 0);
    for(int i=0; i<words.size(); ++i) {
        auto it = m.find(words[i]);
        if(it!=m.end()) {
            for(auto &v: it->second)
                v.push_back(-1);
        } else {
            m[words[i]]=vector<list<int>>(len, {-1});
        }
    }

    int end = s.size()-len+1;
    for(int i=0; i<end; ++i) {
        if(i<len) start[i] = i;
        auto t = s.substr(i, len);
        auto it = m.find(t);
        if(it != m.end()) {
            if(it->second[i%len].front()>=start[i%len]) 
                start[i%len] = it->second[i%len].front() + len;
            it->second[i%len].pop_front();
            it->second[i%len].push_back(i);
            if(i+len-start[i%len] == len*words.size())
                res.push_back(start[i%len]);
        } else {
            start[i%len] = i+len;
        }
    }
    return res;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(words.size()==0 || words[0].size()==0) return res;
    int L=words[0].size();
    vector<unordered_map<string, int>> cache(L);
    for(auto v: words) {
        for(int i=0; i<cache.size(); ++i) ++cache[i][v];
    }
    vector<int> start(L), end(L), counter(L, 0);
    for(int i=0; i<start.size(); ++i) start[i]=end[i]=i;
    for(int i=0; i<s.size(); ++i) {
        int pos = i%L;
        if(cache[pos][s.substr(i, L)]--==0) ++counter[pos];
        while(counter[pos]>0) {
            if(cache[pos][s.substr(start[pos], L)]++<0) --counter[pos];
            start[pos]+=L;
        }
        if(i+L-start[pos]==L*words.size()) res.push_back(start[pos]);
    }
    return res;
}

int main() {
    vector<string> words = {"bar","foo","the"};
    auto res = findSubstring("barfoofoobarthefoobarthe", words);
    //vector<string> words = {"bar","foo"};
    //auto res = findSubstring("barfoothefoobarman", words);
    //vector<string> words = {"word","good","best","good"};
    //auto res = findSubstring("wordgoodgoodgoodbestword", words);
    //vector<string> words = {"aa", "aa", "aa"};
    //auto res = findSubstring("aaaaaaaa", words);
    for(auto &i: res) 
        cout << i << "\t";
    cout << endl;
}
