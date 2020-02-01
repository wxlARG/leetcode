#include"common.h"
using namespace std;

int helper(vector<vector<int>>& heightMap, vector<vector<bool>>& visited, int x, int y, int px, int py, int& res, set<vector<int>>& cache, map<int, set<vector<int>>>& bound) {
    vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1},{0, 1}};
    int count=0;
    do {
        if(visited[x][y]) break;
        if(x==0 || x==heightMap.size()-1 || y==0 || y==heightMap[0].size()-1) break;
        bool b=false;
        for(auto& p: dir) {
            if(cache.count({x+p[0], y+p[1]})) continue;
            if(heightMap[x][y]>heightMap[x+p[0]][y+p[1]]) {
                auto tmp=helper(heightMap, visited, x+p[0], y+p[1], x, y, res, cache, bound);
                if(tmp<0) {b=true;break;}
                else count+=tmp;
            }
        }
        visited[x][y]=true;
        cache.insert({x, y});
        if(b) break;
        ++count;
        for(auto& p: dir) {
            if(cache.count({x+p[0], y+p[1]})==0) {
                bound[heightMap[x+p[0]][y+p[1]]].insert({x+p[0], y+p[1]});
            }
        }
        auto it=bound.begin();
        if(it->first<heightMap[x][y]) break;
        res+=count*(it->first-heightMap[x][y]);
        auto next=it->second.begin();
        x=(*next)[0], y=(*next)[1];
        it->second.erase(it->second.begin());
        if(it->second.empty()) bound.erase(it);
        if(x==px && y==py) return count;
    } while(!bound.empty());
    return -1;
}

int trapRainWater(vector<vector<int>>& heightMap) {
    int res=0;
    if(heightMap.empty()) return res;
    vector<vector<bool>> visited(heightMap.size(), vector<bool>(heightMap[0].size(), false));
    for(int i=0; i<heightMap.size(); ++i) {
        for(int j=0; j<heightMap[i].size(); ++j) {
            map<int, set<vector<int>>> bound;
            set<vector<int>> cache;
            helper(heightMap, visited, i, j, -1, -1, res, cache, bound);
        }
    }
    return res;
}

int main() {
    /*vector<vector<int>> heightMap = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };*/
    /*vector<vector<int>> heightMap = {
            {12,13,1,12},
            {13,4,13,12},
            {13,8,10,12},
            {12,13,12,12},
            {13,13,13,13}
    };*/
    /*vector<vector<int>> heightMap = {
        {5,5,5,1},
        {5,1,1,5},
        {5,1,5,5},
        {5,2,5,8}
    };*/
    vector<vector<int>> heightMap = {
        {9,9,9,9,9},
        {9,2,1,2,9},
        {9,2,8,2,9},
        {9,2,3,2,9},
        {9,9,9,9,9},
    };
    /*vector<vector<int>> heightMap = {
        {14,17,18,16,14,16},
        {17,3,10,2,3,8},
        {11,10,4,7,1,7},
        {13,7,2,9,8,10},
        {13,1,3,4,8,6},
        {20,3,3,9,10,8}
    };*/

    cout << trapRainWater(heightMap) << endl;
}
