#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool int_less(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals)
{
	vector<Interval> result;
	sort(intervals.begin(), intervals.end(), int_less);

	for(int i=0; i<intervals.size(); ++i)
	{
		if(result.empty())
			result.push_back(intervals[i]);
		else
		{
			Interval& last = result.back();

			if(last.end >= intervals[i].start)
			{
				if(last.end <intervals[i].end)
					last.end = intervals[i].end;
			}
			else
				result.push_back(intervals[i]);
		}
	}

	return result;
}

int main()
{
	vector<Interval> intervals;

	Interval tmp(1,4);
	intervals.push_back(tmp);

	tmp.start = 0;
	tmp.end = 2;
	intervals.push_back(tmp);

	tmp.start = 3;
	tmp.end = 5;
	intervals.push_back(tmp);

	vector<Interval> result = merge(intervals);
	for(int i=0; i<result.size(); ++i)
		cout << result[i].start << "\t" << result[i].end << endl;

	return 0;
}
