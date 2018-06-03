#include<iostream>
#include<vector>
#include<unordered_map>
#include"common.h"
using namespace std;

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if(intervals.size()==0) return res;
    auto less = [](const Interval& v1, const Interval& v2) -> bool const {
        return v1.start<v2.start;
    };
    sort(intervals.begin(), intervals.end(), less);
    int start=intervals[0].start, end=intervals[0].end;
    for(int i=1; i<intervals.size(); ++i) {
        if(intervals[i].start<=end) {
            end = max(intervals[i].end, end);
        } else {
            res.push_back(Interval(start, end));
            start = intervals[i].start;
            end = intervals[i].end;
        }
    }
    res.push_back(Interval(start, end));
    return res;
}

int main() {
    //vector<Interval> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<Interval> intervals = {{1, 4}, {2, 3}};
    auto res = merge(intervals);
    for(auto &v: res) {
        cout << v.start << "\t" << v.end << endl;
    }
}
