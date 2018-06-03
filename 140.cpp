#include"common.h"
using namespace std;

void dfs(string &s, int end, vector<string>& res, string& str, vector<vector<int>>& cache) {
    if(end<0) {
        str.pop_back();
        res.push_back(str);
        return;
    }
    string tmp=str;
    for(auto pos: cache[end]) {
        str=s.substr(pos, end-pos+1)+" " + str;
        dfs(s, pos-1, res, str, cache);
        str=tmp;
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordCache;
    vector<string> res;
    for(auto &str: wordDict) wordCache.insert(str);
    vector<vector<int>> cache(s.size()+1);
    for(int i=0; i<s.size(); ++i) {
        for(int j=-1; j<i; ++j) {
            if((j==-1 || cache[j].size()!=0) && wordCache.find(s.substr(j+1, i-j))!=wordCache.end()) {
                cache[i].push_back(j+1);
            }
        }
    }
    string str;
    dfs(s, s.size()-1, res, str, cache);
    return res;
}

int main() {
    vector<string> wordDict={"cat", "cats", "and", "sand", "dog"};
    auto res = wordBreak("catsanddog", wordDict);
    for(auto &str: res) cout << str << endl;
}
