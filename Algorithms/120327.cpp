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

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval> result;
	bool flag = 0;

	for(int i=0; i<intervals.size(); ++i)
	{
		Interval cur = intervals[i];
		if(flag==0 && cur.start>newInterval.start)
		{
			cur = newInterval;
			flag = 1;
			--i;
		}

		if(result.empty())
			result.push_back(cur);
		else
		{
			Interval& last = result.back();

			if(last.end >= cur.start)
			{
				if(last.end < cur.end)
					last.end = cur.end;
			}
			else
				result.push_back(cur);
		}
	}

	if(flag == 0)
	{
		if(result.empty())
			result.push_back(newInterval);
		else
		{
			Interval& last = result.back();

			if(last.end >= newInterval.start)
			{
				if(last.end < newInterval.end)
					last.end = newInterval.end;
			}
			else
				result.push_back(newInterval);
		}
	}
	return result;
}

int main()
{
	vector<Interval> intervals;

	Interval tmp(1,2);
	intervals.push_back(tmp);

	tmp.start = 3;
	tmp.end = 5;
	intervals.push_back(tmp);

	tmp.start = 6;
	tmp.end = 7;
	intervals.push_back(tmp);

	tmp.start = 8;
	tmp.end = 10;
	intervals.push_back(tmp);

	tmp.start = 12;
	tmp.end = 16;
	intervals.push_back(tmp);

	Interval newInterval(4,9);

	vector<Interval> result = insert(intervals,newInterval);
	for(int i=0; i<result.size(); ++i)
		cout << result[i].start << "\t" << result[i].end << endl;

	return 0;
}
