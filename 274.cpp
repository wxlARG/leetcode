#include"common.h"
using namespace std;

int hIndex_solution1(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int res=0, end=citations.size()-1;
    for(int i=end, num=1; i>=0; --i, ++num) {
        if(citations[i]>=num) res=num;
        else break;
    }
    return res;
}

int hIndex_solution2(vector<int>& citations) {
    int res=0, le_res=0;
    unordered_map<int, int> cache;
    for(auto &v: citations) {
        ++cache[v];
        if(v>=res) ++le_res;
        int num=(cache.find(res)==cache.end()? 0: cache[res]);
        if(le_res-res>num) {
            ++res;
            le_res-=num;
        }
    }
    return res;
}

int hIndex(vector<int>& citations) {
    int h=0, eq_h=0, le_h=0;
    unordered_map<int, int> cache;
    for(auto &v: citations) {
        if(v<h) continue;
        ++cache[v];
        ++le_h;
        if(v==h) ++eq_h;
        if(le_h-eq_h>=h+1) {
            ++h;
            le_h-=eq_h;
            eq_h=cache[h];
        }
    }
    return h;
}

int main() {
    //vector<int> citations={3,0,6,1,5,7,8};
    vector<int> citations={0, 1, 0};
    cout << hIndex(citations) << endl;
}
