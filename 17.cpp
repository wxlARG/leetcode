#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void helper(string digits, int pos, string& str, vector<string>& res, unordered_map<char, string>& cache) {
    if(pos == digits.size()) {
        res.push_back(str);
        return;
    }
    for(auto &c : cache[digits[pos]]) {
        str.push_back(c);
        helper(digits, pos+1, str, res, cache);
        str.pop_back();
    }
}

vector<string> letterCombinations_solution1(string digits) {
    vector<string> res;
    if(digits.size() == 0) return res;
    unordered_map<char, string> cache = {
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
        {'0', " "},
    };
    string str;
    helper(digits, 0, str, res, cache);
    return res;
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.size() == 0) return res;
    vector<string> cache = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str;

    do {
        str.push_back(cache[digits[str.size()]-'0'][0]);
        while(str.size() == digits.size()) {
            res.push_back(str);
            while(!str.empty() && str.back()+1>cache[digits[str.size()-1]-'0'].back())
                str.pop_back();
           if(!str.empty()) ++str.back(); 
        }
    } while(!str.empty());
    return res;
}

int main() {
    auto res = letterCombinations("23");
    for(auto &v : res)
        cout << v << "\t";
    cout << endl;
}
