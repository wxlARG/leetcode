#include"common.h"
using namespace std;

int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    vector<int> cache;
    auto cmp=[](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first<b.first || (a.first==b.first && a.second>b.second);
    };
    sort(envelopes.begin(), envelopes.end(), cmp);
    for(auto& item: envelopes) {
        auto it=lower_bound(cache.begin(), cache.end(), item.second);
        if(it==cache.end()) cache.push_back(item.second);
        else *it=item.second;
    }
    return cache.size();
}

int main() {
    //vector<pair<int, int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    vector<pair<int, int>> envelopes = {{4,5},{4,6},{6,7},{2,3},{1,1}};
    cout << maxEnvelopes(envelopes) << endl;
}
