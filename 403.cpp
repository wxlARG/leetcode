#include"common.h"
using namespace std;

bool canCross(vector<int>& stones) {
    unordered_map<int, int> dict;
    for(int i=0; i<stones.size(); ++i) dict[stones[i]]=i;
    vector<unordered_set<int>> cache(stones.size());
    cache[0].insert(1);
    for(int i=0; i<stones.size(); ++i) {
        if(cache[i].empty()) continue;
        for(auto v: cache[i]) {
            if(dict.find(stones[i]+v)==dict.end()) continue;
            if(dict[stones[i]+v]==stones.size()-1) return true;
            cache[dict[stones[i]+v]].insert({v-1, v, v+1});
        }
    }
    return false;
}

int main() {
    vector<int> stones = {0,1,3,5,6,8,12,17};
    //vector<int> stones = {0,1,2,3,4,8,9,11};
	cout << canCross(stones) << endl;
}
