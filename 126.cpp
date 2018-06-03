#include"common.h"
using namespace std;

void helper_solution1(int end_pos, vector<string>& r, vector<vector<int>>& cache, vector<string>& wordList, vector<vector<string>>& res) {
    if(end_pos==wordList.size()-1) {
        r.push_back(wordList[end_pos]);
        reverse(r.begin(), r.end());
        res.push_back(r);
        reverse(r.begin(), r.end());
        r.pop_back();
        return;
    }
    for(int i=1; i<cache[end_pos].size(); ++i) {
        r.push_back(wordList[end_pos]);
        helper_solution1(cache[end_pos][i], r, cache, wordList, res);
        r.pop_back();
    }
}

vector<vector<string>> findLadders_solution1(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    vector<string> r;
    wordList.push_back(beginWord);
    vector<vector<int>> cache(wordList.size());
    cache.back() = {0, 0};
    deque<int> q={int(wordList.size())-1};
    bool found=false;
    int step=0, end_pos=-1;
    while(!q.empty() && !found) {
        int queue_size=q.size();
        ++step;
        for(int i=0; i<queue_size; ++i) {
            int pos=q.front();
            q.pop_front();
            if(wordList[pos]==endWord) {
                found=true;
                end_pos=pos;
                break;
            }
            for(int j=0; j<wordList.size(); ++j) {
                if(cache[j].size()!=0 && cache[j].front()<step) continue;
                int diff_char=0;
                for(int k=0; k<wordList[pos].size(); ++k) if(wordList[pos][k]!=wordList[j][k]) ++diff_char;
                if(diff_char==1) {
                    if(cache[j].size()==0) {
                        q.push_back(j);
                        cache[j].push_back(step);
                    }
                    cache[j].push_back(pos);
                }
            }
        }
    }
    if(end_pos!=-1) helper_solution1(end_pos, r, cache, wordList, res);
    return res;
}

void dfs(const string& beginWord, const string& endWord, unordered_map<string, unordered_set<string>>& cache, vector<string>& rs, vector<vector<string>>& res) {
    if(beginWord==endWord) {
        res.push_back(rs);
        return;
    }
    for(auto &nstr: cache[beginWord]) {
        rs.push_back(nstr);
        dfs(nstr, endWord, cache, rs, res);
        rs.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    vector<string> rs={beginWord};
    unordered_set<string> cache={beginWord}, sq={beginWord}, eq={endWord};
    for(auto &s: wordList) cache.insert(s);
    unordered_map<string, unordered_set<string>> nexts;
    if(cache.find(endWord)==cache.end()) return res;
    bool found=false, d=true;
    while(!sq.empty() && !eq.empty() && !found) {
        if(sq.size()>eq.size()) {
            sq.swap(eq);
            d=!d;
        }
        unordered_set<string> tq;
        for(auto &s: sq) cache.erase(s);
        for(auto &s: sq) {
            string ts=s;
            for(int l=0; l<ts.size(); ++l) {
                int tc=ts[l];
                for(int c='a'; c<='z'; ++c) {
                    ts[l]=c;
                    if(cache.find(ts)==cache.end()) continue;
                    tq.insert(ts);
                    if(eq.find(ts)!=eq.end()) found=true;
                    if(d) nexts[s].insert(ts);
                    else nexts[ts].insert(s);
                }
                ts[l]=tc;
            }
        }
        sq.swap(tq);
    }
    dfs(beginWord, endWord, nexts, rs, res);
    return res;
}

int main() {
    //vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    //auto res = findLadders("hit", "cog", wordList);
    vector<string> wordList = {"ted","tex","tax","red","tad","den","rex","pee"};
    auto res = findLadders("red", "tax", wordList);
    for(auto &vec: res) {
        for(auto &s: vec) cout << s << "\t";
        cout << endl;
    }
}
