#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<stack>
using namespace std;

void helper(int left, int right, string &s, vector<string> &res) {
    if(left == 0 && right == 0) {
        res.push_back(s);
        return;
    }
    if(left != 0) {
        s.push_back('(');
        helper(left-1, right, s, res);
        s.pop_back();
    }
    if(left < right) {
        s.push_back(')');
        helper(left, right-1, s, res);
        s.pop_back();
    }
}

vector<string> generateParenthesis_solution1(int n) {
    vector<string> res;
    string s;
    helper(n, n, s, res);
    return res;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n == 0) return res;
    string s;
    int left=n, right=n;
    do {
        while(left) {
            s.push_back('(');
            --left;
        }
        while(right) {
            s.push_back(')');
            --right;
        }
        res.push_back(s);
        while(!s.empty()) {
            if(s.back()==')') {
                ++right;
                s.pop_back();
            } else if(left+1<right) {
                s.back() = ')';
                ++left;
                --right;
                break;
            } else {
                ++left;
                s.pop_back();
            }
        }
    } while(!s.empty());
    return res;
}

int main() {
    auto res = generateParenthesis(3);
    for(auto &s: res)
        cout << s << endl;
}
