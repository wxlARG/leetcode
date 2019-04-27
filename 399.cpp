#include"common.h"
using namespace std;

string find_parent(string& s, unordered_map<string, pair<string, double>>& dict) {
    if(dict.count(s)==0) {
        dict[s] = {s, 1.0};
    } else if(dict[s].first != s) {
        auto tmp = dict[s].first;
        dict[s].first = find_parent(dict[s].first, dict);
        dict[s].second *= dict[tmp].second;
    }
    return dict[s].first;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    vector<double> res;
    unordered_map<string, pair<string, double>> dict;
    for(int i=0; i<equations.size(); ++i) {
        string p1=find_parent(equations[i].first, dict);
        string p2=find_parent(equations[i].second, dict);
        if(p1!=p2) {
            dict[p2].first=p1;
            dict[p2].second=values[i]*dict[equations[i].first].second/dict[equations[i].second].second; 
        }
    }
    for(int i=0; i<queries.size(); ++i) {
        if(dict.count(queries[i].first)==0 || dict.count(queries[i].second)==0) res.push_back(-1);
        else if(find_parent(queries[i].first, dict)!=find_parent(queries[i].second, dict)) res.push_back(-1);
        else res.push_back(dict[queries[i].second].second/dict[queries[i].first].second);
    }
    return res;
}

int main() {
    vector<double> values = {2.0, 3.0};
    auto res = calcEquation({{"a", "b"}, {"b", "c"}}, values, {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}});
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
