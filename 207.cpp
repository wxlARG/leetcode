#include"common.h"
using namespace std;

bool dfs(unordered_map<int, vector<int>>& graph, vector<char>& visited, int v) {
    visited[v]=1;
    for(auto &next: graph[v]) {
        if(visited[next]==2) continue;
        if(visited[next]==1) return false;
        if(dfs(graph, visited, next)==false) return false;
    }
    visited[v]=2;
    return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    for(auto &p: prerequisites) graph[p.first].push_back(p.second);
    vector<char> visited(numCourses, 0);
    for(int v=0; v<numCourses; ++v) {
        if(!visited[v]) {
            if(!dfs(graph, visited, v)) return false; 
        }
    }
    return true;
}

int main() {
    //vector<pair<int, int>> prerequisites = {{1, 0}, {0, 1}};
    vector<pair<int, int>> prerequisites = {{1, 2}, {3, 2}, {2, 4}, {4, 3}};
    cout << canFinish(2, prerequisites) << endl;
}
