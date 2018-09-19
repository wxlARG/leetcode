#include"common.h"
using namespace std;

int helper_solution1(int node, vector<int>& height, vector<bool>& visit, vector<vector<int>>& conn) {
    int h=0;
    visit[node]=true;
    for(auto& c: conn[node]) {
        if(!visit[c]) h=max(h, helper_solution1(c, height, visit, conn));
    }
    height[node]=h+1;
    return h+1;
}

vector<int> findMinHeightTrees_solution1(int n, vector<pair<int, int>>& edges) {
    if(n==0) return {};
    vector<vector<int>> conn(n);
    for(auto& edge: edges) {
        conn[edge.first].push_back(edge.second);
        conn[edge.second].push_back(edge.first);
    }
    vector<int> height(n, 0);
    vector<bool> visit(n, false);
    helper_solution1(0, height, visit, conn);
    vector<int> res={0};
    int node=0, cur_height=height[0];
    while(1) {
        vector<pair<int, int>> child_height(2, {0, 0});
        for(auto& c: conn[node]) {
            if(height[c]>=child_height[0].second) {
                child_height[1].first=child_height[0].first;
                child_height[1].second=child_height[0].second;
                child_height[0].first=c;
                child_height[0].second=height[c];
            } else if(height[c]>=child_height[1].second) {
                child_height[1].first=c;
                child_height[1].second=height[c];
            }
        }
        int new_height=max(child_height[1].second+2, child_height[0].second);
        if(new_height>=cur_height) {
            if(new_height==cur_height) res.push_back(child_height[0].first);
            break;
        }
        res={child_height[0].first};
        height[node]=child_height[1].second+1;
        cur_height=new_height;
        node=child_height[0].first;
    }
    return res;
}

vector<int> findMinHeightTrees_solution2(int n, vector<pair<int, int>>& edges) {
    if(n==0) return {};
    if(n==1) return {0};
    deque<int> res;
    vector<unordered_set<int>> conn(n);
    for(auto& edge: edges) {
        conn[edge.first].insert(edge.second);
        conn[edge.second].insert(edge.first);
    }
    int count=n;
    for(int node=0; node<n; ++node) {
        if(conn[node].size()==1) {
            res.push_back(node);
            --count;
        }
    }
    while(count) {
        int num=res.size();
        for(int i=0; i<num; ++i) {
            int v=res.front();
            res.pop_front();
            for(auto& node: conn[v]) {
                conn[node].erase(v);
                if(conn[node].size()==1) {
                    res.push_back(node);
                    --count;
                }
            }
        }
    }
    return {res.begin(), res.end()};
}

void help_in(vector<vector<int>>& conn, vector<int>& in, int point, int parent) {
    for(auto& v: conn[point]) {
        if(v==parent) continue;
        help_in(conn, in, v, point);
        in[point]=max(in[point], in[v]);
    }
    in[point]+=1;
}

void help_out(vector<vector<int>>& conn, vector<int>& in, vector<int>& out, int point, int parent) {
    pair<int, int> mh={0, 0};
    for(auto& v: conn[point]) {
        if(v==parent) continue;
        if(in[v]>=mh.first) {
            mh.second=mh.first;
            mh.first=in[v];
        } else if(in[v]>mh.second) {
            mh.second=in[v];
        }
    }
    for(auto& v: conn[point]) {
        if(v==parent) continue;
        int h=mh.first;
        if(in[v]==mh.first) h=mh.second;
        out[v]=max(out[point], h+1)+1;
        help_out(conn, in, out, v, point);
    }
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if(n==0) return {};
    vector<int> in(n, 0), out(n, 0), res;
    vector<vector<int>> conn(n);
    for(auto& edge: edges) {
        conn[edge.first].push_back(edge.second);
        conn[edge.second].push_back(edge.first);
    }
    help_in(conn, in, 0, -1);
    out[0]=1;
    help_out(conn, in, out, 0, -1);
    int mh=INT_MAX;
    for(int i=0; i<n; ++i) mh=min(mh, max(in[i], out[i]));
    for(int i=0; i<n; ++i) {
        if(max(in[i], out[i])==mh) res.push_back(i);
    }
    return res;
}

int main() {
    vector<pair<int, int>> edges={{1, 0}, {1, 2}, {1, 3}};
    //vector<pair<int, int>> edges={{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    //vector<pair<int, int>> edges={{0, 1}, {0, 2}};
    auto res=findMinHeightTrees(4, edges);
    for(auto& v: res) cout << v << endl;
}
