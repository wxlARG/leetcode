#include"common.h"
using namespace std;

vector<pair<int, int>> getSkyline_solution1(vector<vector<int>>& buildings) {
    auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool const {
        return p1.first>p2.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    map<int, int> tmap;
    vector<pair<int, int>> res;
    for(auto &vec: buildings) {
        int left=vec[0], right=vec[1], height=vec[2];
        while(!pq.empty() && pq.top().first<left) {
            int r=pq.top().first, h=pq.top().second;
            if(--tmap[h]==0) {
                auto mit=tmap.rbegin();
                if(h==mit->first) {
                    auto next_height=((++mit)==tmap.rend()? 0: mit->first);
                    if(res.back().first==r && res.back().second>next_height) res.back().second=next_height;
                    else if(res.back().second!=next_height) res.push_back({r, next_height});
                }
                tmap.erase(h);
            }
            pq.pop();
        }
        auto mit = tmap.rbegin();
        if(tmap.empty() || height>mit->first) {
            if(!res.empty() && res.back().first==left) res.back().second=height;
            else if(res.empty() || res.back().second!=height) res.push_back({left, height});
        }
        ++tmap[height];
        pq.push({right, height});
    }
    while(!pq.empty()) { 
        int r=pq.top().first, h=pq.top().second;
        if(--tmap[h]==0) {
            auto mit=tmap.rbegin();
            if(h==mit->first) {
                auto next_height=((++mit)==tmap.rend()? 0: mit->first);
                if(res.back().first==r && res.back().second>next_height) res.back().second=next_height;
                else if(res.back().second!=next_height) res.push_back({r, next_height});
            }
            tmap.erase(h);
        }
        pq.pop();
    }
    return res;
}

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool const {
        return p1.first>p2.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    vector<pair<int, int>> res;
    set<pair<int, int>> cache;
    for(int i=0; i<buildings.size() || !pq.empty(); ) {
        int pos=(i<buildings.size()? buildings[i][0]: INT_MAX);
        while(!pq.empty() && pq.top().first<=pos) {
            pos=pq.top().first;
            cache.erase({pq.top().second, pq.top().first});
            pq.pop(); 
        }
        while(i<buildings.size() && pos==buildings[i][0]) {
            cache.insert({buildings[i][2], buildings[i][1]});
            pq.push({buildings[i][1], buildings[i][2]});
            ++i;
        }
        int height=(cache.empty()? 0: cache.rbegin()->first);
        if(res.empty() || res.back().second!=height) res.push_back({pos, height});
    }
    return res;
}

int main() {
    vector<vector<int>> buildings = {
        {2,9,10}, {3,7,15}, {5,12,12},
        {15,20,10}, {19,24,8}
    };
    auto res=getSkyline(buildings);
    for(auto &v: res) cout << v.first << "\t" << v.second << endl;
}
