#include"common.h"
using namespace std;

int ladderLength_solution1(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    vector<vector<int>> c=vector<vector<int>>(wordList.size());
    int start=wordList.size()-1, end=-1;
    for(int i=0; i<wordList.size(); ++i) {
        if(endWord==wordList[i]) end=i;
        for(int j=i+1; j<wordList.size(); ++j) {
            string &s1=wordList[i], &s2=wordList[j];
            int diff_char=0;
            for(int k=0; k<s1.size(); ++k) if(s1[k]!=s2[k]) ++diff_char;
            if(diff_char==1) {
                c[i].push_back(j);
                c[j].push_back(i);
            }
        }
    }
    deque<int> q={start};
    int step=0;
    while(!q.empty()) {
        int queue_size=q.size();
        ++step;
        for(int i=0; i<queue_size; ++i) {
            int pos=q.front();
            q.pop_front();
            if(pos==end) return step;
            if(c[pos].size()!=0 && c[pos].back()!=-1) {
                for(auto &p: c[pos]) q.push_back(p);
                c[pos].push_back(-1);
            }
        }
    }
    return 0;
}

int ladderLength_solution2(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    vector<bool> cache(wordList.size(), false);
    cache.back()=true;
    deque<int> q={int(wordList.size())-1};
    int step=0;
    while(!q.empty()) {
        int queue_size=q.size();
        ++step;
        for(int i=0; i<queue_size; ++i) {
            int pos=q.front();
            q.pop_front();
            if(wordList[pos]==endWord) return step;
            for(int j=0; j<wordList.size(); ++j) {
                if(cache[j]) continue;
                int diff_char=0;
                for(int k=0; k<wordList[pos].size(); ++k) if(wordList[pos][k]!=wordList[j][k]) ++diff_char;
                if(diff_char==1) {
                    q.push_back(j);
                    cache[j] = true;
                }
            }
        }
    }
    return 0;
}

int ladderLength_solution3(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> cache={beginWord}, sq={beginWord}, eq={endWord};
    for(auto &s: wordList) cache.insert(s);
    if(cache.find(endWord)==cache.end()) return 0;
    int step=0;
    while(!sq.empty() && !eq.empty()) {
        unordered_set<string>& pq=(sq.size()<eq.size()? sq: eq);
        unordered_set<string>& qq=(sq.size()>=eq.size()? sq: eq);
        unordered_set<string> tq;
        ++step;
        for(auto s: pq) {
            cache.erase(s);
            if(qq.find(s)!=qq.end()) return step;
            for(int l=0; l<s.size(); ++l) {
                int tc=s[l];
                for(int c='a'; c<='z'; ++c) {
                    s[l]=c;
                    if(cache.find(s)!=cache.end()) tq.insert(s);
                }
                s[l]=tc;
            }
        }
        swap(pq, tq);
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> cache={beginWord}, sq={beginWord}, eq={endWord};
    for(auto &s: wordList) cache.insert(s);
    if(cache.find(endWord)==cache.end()) return 0;
    int step=0;
    while(!sq.empty() && !eq.empty()) {
        if(sq.size()>eq.size()) sq.swap(eq);
        unordered_set<string> tq;
        ++step;
        for(auto s: sq) {
            cache.erase(s);
            for(int l=0; l<s.size(); ++l) {
                int tc=s[l];
                for(int c='a'; c<='z'; ++c) {
                    s[l]=c;
                    if(cache.find(s)!=cache.end()) tq.insert(s);
                    if(eq.find(s)!=eq.end()) return ++step;
                }
                s[l]=tc;
            }
        }
        sq.swap(tq);
    }
    return 0;
}

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log", "cog"};
    cout << ladderLength("hit", "cog", wordList) << endl;
}
