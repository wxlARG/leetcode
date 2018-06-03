#include"common.h"
using namespace std;

int dfs(vector<vector<int>>& graph, vector<char>& color, vector<int>& res, int pos) {
    color[pos]=1;
    for(auto &v: graph[pos]) {
        if(color[v]==1) return 1;
        else if(color[v]==0 && dfs(graph, color, res, v)) return 1;
    }
    res.push_back(pos);
    color[pos]=2;
    return 0;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    for(auto &p: prerequisites) graph[p.first].push_back(p.second);
    vector<char> color(numCourses, 0); 
    vector<int> res;

    for(int i=0; i<numCourses; ++i) {
        if(color[i]) continue;
        if(dfs(graph, color, res, i)) return vector<int>();
    }
    return res;
}

int main() {
    vector<pair<int, int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
    auto res = findOrder(4, prerequisites);
    for(auto &v: res) cout << v << "\t";
    cout << endl;
}
