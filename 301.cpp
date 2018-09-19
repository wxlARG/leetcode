#include"common.h"
using namespace std;

bool is_valid(string& s) {
    int left=0, right=0;
    for(auto& c: s) {
        if(c=='(') ++left;
        else if(c==')') ++right;
        if(left<right) return false;
    }
    return left==right;
}

vector<string> removeInvalidParentheses_solution1(string s) {
	queue<string> bfs;
    bfs.push(s);
    vector<string> res;
    while(!bfs.empty() && res.empty()) {
        int size=bfs.size();
        unordered_set<string> cache;
        for(int i=0; i<size; ++i) {
            string str=bfs.front();
            bfs.pop();
            if(is_valid(str)) {
                res.push_back(str);
            } else if(res.empty()) {
                for(int j=0; j<str.size(); ++j) {
                    string ss=str.substr(0, j)+str.substr(j+1);
                    if(cache.find(ss)==cache.end()) {
                        cache.insert(ss);
                        bfs.push(ss);
                    }
                }
            }
        }
    }
    return res;
}

void helper(vector<string>& res, string& cache, int left, int right, int lnum, int rnum, string& s, int pos) {
    if(rnum>lnum) return;
    if(pos==s.size()) {
        if(left==0 && right==0) res.push_back(cache);
        return;
    }
    if(s[pos]=='(' && left>0 && right==0 && (cache.empty() || s[pos]!=cache.back())) {
        helper(res, cache, left-1, right, lnum, rnum, s, pos+1);
    }
    if(s[pos]==')' && right>0 && (cache.empty() || s[pos]!=cache.back())) {
        helper(res, cache, left, right-1, lnum, rnum, s, pos+1);
    }
    cache.push_back(s[pos]);
    helper(res, cache, left, right, lnum+(s[pos]=='('? 1: 0), rnum+(s[pos]==')'? 1: 0), s, pos+1);
    cache.pop_back();
}

vector<string> removeInvalidParentheses(string s) {
    int left=0, right=0;
    for(auto& c: s) {
        if(c=='(') ++left;
        if(c==')') {
            if(left>0) --left;
            else ++right;
        }
    }
    vector<string> res;
    string cache;
    helper(res, cache, left, right, 0, 0, s, 0);
    return res;
}

int main() {
    //auto res = removeInvalidParentheses("()())()");
    auto res = removeInvalidParentheses(")()))())))");
    //auto res = removeInvalidParentheses(")()(");
    for(auto& str: res) cout << str << endl;
}
