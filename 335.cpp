#include"common.h"
using namespace std;

bool isSelfCrossing_solution1(vector<int>& x) {
    deque<pair<int, int>> paths(5, {0, 0});
    int limit=INT_MAX;
    for(int i=0; i<x.size(); ++i) {
        pair<int, int> cur;
        if(i%4==0) {
            cur={paths.back().first, paths.back().second+x[i]};
            if(cur.second>=limit) return true;
            if(paths[4].first<paths[1].first || cur.second<paths[0].second) limit=paths[2].first;
            else if(cur.second<=paths[1].second) limit=paths[1].first;
            else limit=INT_MIN;
        } else if(i%4==1) {
            cur={paths.back().first-x[i], paths.back().second};
            if(cur.first<=limit) return true;
            if(paths[4].second<paths[1].second || cur.first>paths[0].first) limit=paths[2].second;
            else if(cur.first>=paths[1].first) limit=paths[1].second;
            else limit=INT_MIN;
        } else if(i%4==2) {
            cur={paths.back().first, paths.back().second-x[i]};
            if(cur.second<=limit) return true;
            if(paths[4].first>paths[1].first || cur.second>paths[0].second) limit=paths[2].first;
            else if(cur.second>=paths[1].second) limit=paths[1].first;
            else limit=INT_MAX;
        } else {
            cur={paths.back().first+x[i], paths.back().second};
            if(cur.first>=limit) return true;
            if(paths[4].second>paths[1].second || cur.first<paths[0].first) limit=paths[2].second;
            else if(cur.first<=paths[1].first) limit=paths[1].second;
            else limit=INT_MAX;
        }
        paths.pop_front();
        paths.push_back(cur);
    }
    return false;
}

bool isSelfCrossing(vector<int>& x) {
    for(int i=3; i<x.size(); ++i) {
        if(x[i-1]>x[i-3]) continue;
        if(i>=4 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2]) return true;
        if(i>=5 && x[i-2]>x[i-4] && x[i-1]+x[i-5]>=x[i-3] && x[i]+x[i-4]>=x[i-2]) return true;
        if(x[i]>=x[i-2]) return true;
    }
    return false;
}

int main() {
    //vector<int> x={2,1,1,2};
    //vector<int> x={1,2,3,4};
    vector<int> x={1,1,1,1};
    //vector<int> x={3,3,3,2,1,1};
    cout << isSelfCrossing(x) << endl;
}
