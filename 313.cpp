#include"common.h"
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> dp(1, 1);
    auto greater=[&](pair<int, int>& p1, pair<int, int>& p2) -> bool {
        return p1.first*dp[p1.second]>p2.first*dp[p2.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> pq(greater);
    for(auto& v: primes) pq.push({v, 0});
    while(dp.size()<n) {
        auto val=pq.top();
        pq.pop();
        if(val.first*dp[val.second]>dp.back()) dp.push_back(val.first*dp[val.second]);
        pq.push({val.first, val.second+1});
    }
    return dp.back();
}

int main() {
    vector<int> primes={2,7,13,19};
    cout << nthSuperUglyNumber(12, primes) << endl;
}
