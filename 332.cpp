#include"common.h"
using namespace std;

bool dfs_solution1(unordered_map<string, multiset<string>>& paths, string& from, int num, vector<string>& res) {
    res.push_back(from);
    --num;
    if(num==0) return true;
    vector<string> cache(paths[from].begin(), paths[from].end());
    for(auto& dst: cache) {
        paths[from].erase(paths[from].find(dst));
        if(dfs_solution1(paths, dst, num, res)) return true;
        paths[from].insert(dst);
    }
    res.pop_back();
    return false;
}

vector<string> findItinerary_solution1(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> paths;
    vector<string> res;
    for(auto& ticket: tickets) paths[ticket.first].insert(ticket.second);
    string from("JFK");
    dfs_solution1(paths, from, tickets.size()+1, res);
    return res;
}

void dfs_solution2(unordered_map<string, vector<string>>& paths, unordered_map<string, int>& pos, string& from, vector<string>& res) {
    while(pos[from]<paths[from].size()) dfs_solution2(paths, pos, paths[from][pos[from]++], res);
    res.push_back(from);
}

vector<string> findItinerary_solution2(vector<pair<string, string>> tickets) {
    unordered_map<string, vector<string>> paths;
    unordered_map<string, int> pos;
    vector<string> res;
    for(auto& ticket: tickets) paths[ticket.first].push_back(ticket.second);
    for(auto& kv: paths) {
        sort(kv.second.begin(), kv.second.end());
        pos[kv.first]=0;
    }
    string from("JFK");
    dfs_solution2(paths, pos, from, res);
    reverse(res.begin(), res.end());
    return res;
}

void dfs(unordered_map<string, multiset<string>>& paths, string& from, vector<string>& res) { 
    while(!paths[from].empty()) {
        auto it=paths[from].begin();
        string next=*it;
        paths[from].erase(it);
        dfs(paths, next, res);
    }        
    res.push_back(from);
}  
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> paths;
    vector<string> res;
    for(auto& ticket: tickets) paths[ticket.first].insert(ticket.second);
    string from("JFK");
    dfs(paths, from, res);
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    //vector<pair<string, string>> tickets={{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<pair<string, string>> tickets={{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
    auto res=findItinerary(tickets);
    for(auto& s: res) cout << s << "\t";
    cout << endl;
}
