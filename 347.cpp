#include"common.h"
using namespace std;

vector<int> topKFrequent_solution1(vector<int>& nums, int k) {
    vector<unordered_set<int>> frequent(1);
    unordered_map<int, int> count_map;
    vector<int> res;
    for(auto v: nums) {
        int count=count_map[v];
        if(count!=0) frequent[count].erase(v);
        if(count+2>frequent.size()) frequent.push_back(unordered_set<int>());
        frequent[count+1].insert(v);
        ++count_map[v];
    }
    for(int j=frequent.size()-1; k>0 && j>=0; --j) {
        for(auto v: frequent[j]) {
            if(k--<=0) break;
            res.push_back(v);
        }
    }
    return res;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> count_dict;
    for(auto v: nums) ++count_dict[v];
    auto cmp = [&](int v1, int v2) {
        return count_dict[v1]>count_dict[v2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for(auto kv: count_dict) {
        if(pq.size()<k) {
            pq.push(kv.first);
        } else {
            pq.push(kv.first);
            pq.pop();
        }
    }
    while(!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int main() {
    //vector<int> nums = {1,1,1,2,2,3};
    vector<int> nums = {4,1,-1,2,-1,2,3};
    auto res = topKFrequent(nums, 2);
    for(auto v: res) cout << v << "\t";
    cout << endl;
}
