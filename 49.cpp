#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, int> cache;
    for(auto &str: strs) {
        string tmp=str;
        sort(tmp.begin(), tmp.end());
        auto it = cache.find(tmp);
        if(it!=cache.end()) {
            res[it->second].push_back(str);
        } else {
            res.push_back({str});
            cache[tmp] = res.size()-1;
        }
    }
    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = groupAnagrams(strs);
    for(auto &vec: res) {
        for(auto &v: vec) {
            cout << v << "\t";
        }
        cout << endl;
    }
}
