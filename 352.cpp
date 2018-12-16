#include"common.h"
using namespace std;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto nt=intervals.lower_bound(val);
        if(nt!=intervals.end() && nt->first==val) return;
        auto it=intervals.insert({val, val}).first;
        if(nt!=intervals.end() && nt->first==val+1) {
            it->second=nt->second;
            intervals.erase(nt);
        }
        if(it==intervals.begin()) return;
        auto pr=prev(it);
        if(pr->second>=val-1) {
            pr->second=max(it->second, pr->second);
            intervals.erase(it);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(auto& kv: intervals) {
            res.emplace_back(kv.first, kv.second);
        }
        return res;
    }
private:
    map<int, int> intervals;
};

int main() {
	SummaryRanges obj;
    obj.addNum(1);
    obj.addNum(3);
    obj.addNum(7);
    auto res = obj.getIntervals();
    for(auto& v: res) {
        cout << "[" << v.start << ", " << v.end << "], ";
    }
    cout << endl;
    obj.addNum(2);
    obj.addNum(6);
    res = obj.getIntervals();
    for(auto& v: res) {
        cout << "[" << v.start << ", " << v.end << "], ";
    }
    cout << endl;
}
