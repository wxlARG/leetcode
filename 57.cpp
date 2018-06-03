#include<iostream>
#include<vector>
#include<unordered_map>
#include <queue>
#include"common.h"
using namespace std;

vector<Interval> insert_solution1(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    int pos=0;
    while(pos<intervals.size()) {
        if(intervals[pos].end>=newInterval.start) break;
        res.push_back(intervals[pos++]);
    }
    int start = newInterval.start;
    int end = newInterval.end;
    if(pos == intervals.size()) {
        res.push_back(newInterval);
        return res;
    } else if(end<intervals[pos].start) {
        res.push_back(newInterval);
        start = intervals[pos].start;
        end = intervals[pos].end;
    } else {
        start = min(intervals[pos].start, start);
        end = max(intervals[pos].end, end);
    }
    while(++pos<intervals.size()) {
        if(intervals[pos].start<=end) {
            end = max(intervals[pos].end, end);
        } else {
            res.push_back(Interval(start, end));
            start = intervals[pos].start;
            end = intervals[pos].end;
        }
    }
    res.push_back(Interval(start, end));
    return res;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    auto great = [](const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) -> bool const {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, decltype(great)> cache(great);
    if(intervals.size() != 0) {
        cache.push({intervals[0].start, intervals[0].end, 0, 0});
    }
    cache.push({newInterval.start, newInterval.end, 1, 0});
    int start = INT_MAX, end=INT_MIN;
    while(!cache.empty()) {
        auto &v = cache.top();
        int start_i=get<0>(v);
        int end_i=get<1>(v);
        int array=get<2>(v);
        int pos=get<3>(v);
        cache.pop();
        start = min(start, start_i);
        end = max(end, end_i);
        if(array==0 && pos<intervals.size()-1) {
            cache.push({intervals[pos+1].start, intervals[pos+1].end, 0, pos+1});
        }
        if(cache.empty() || end<get<0>(cache.top())) {
            res.push_back(Interval(start, end));
            start = INT_MAX;
            end=INT_MIN;
        }
    }
    return res;
}

int main() {
    vector<Interval> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    auto res = insert(intervals, {4, 9});
    for(auto &v: res) {
        cout << v.start << "\t" << v.end << endl;
    }
}
