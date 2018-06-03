#include"common.h"
using namespace std;

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
}

int main() {
    vector<vector<int>> buildings = {
        {2,9,10}, {3,7,15}, {5,12,12},
        {15,20,10}, {19,24,8}
    };
    auto res=getSkyline(buildings);
    for(auto &v: res) cout << v.first << "\t" << v.second << endl;
}
