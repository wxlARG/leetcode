#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b)
{
	if(a<b)
		swap(a,b);

	while(b!=0)
	{
		int tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}

bool cmp(const Point& p1, const Point& p2) 
{
	return (p1.x < p2.x) || (p1.x==p2.x && p1.y<p2.y);
}

bool equal(const Point& p1, const Point& p2)
{
	return p1.x==p2.x &&  p1.y==p2.y;
}

int maxPoints(vector<Point> &points)
{
	int result = 0;
	if(points.size()==0)
		return result;

	sort(points.begin(),points.end(),cmp);
	vector<int> num;

	int pos = 0;
	int count = 1;
	for(int i=1; i<points.size(); ++i)
	{
		if(equal(points[i],points[i-1]))
			++count;
		else
		{
			if(result<count)
				result = count;
			points[pos++] = points[i-1];
			num.push_back(count);
			count=1;
		}
	}

	if(result<count)
		result = count;
	points[pos++] = points[points.size()-1];
	num.push_back(count);

	vector<vector<int> > zcache(points.size(),vector<int>(2,0));
	vector<unordered_map<int,unordered_map<int,int> > > ncache(points.size());

	for(int i=1; i<num.size(); ++i)
	{
		unordered_map<int, unordered_map<int,int> > ntmp;

		for(int j=i-1; j>=0; --j)
		{
			int disx = points[i].x-points[j].x;
			int disy = points[i].y-points[j].y;

			if(disx==0)
			{
				if(zcache[j][0] == -1)
					continue;

				if(zcache[j][0]!=0)
					zcache[i][0] = zcache[j][0]+num[i];
				else
					zcache[i][0] = num[i]+num[j];

				zcache[j][0] = -1;
				if(result < zcache[i][0])
					result = zcache[i][0];
			}
			else if(disy==0)
			{
				if(zcache[j][1] == -1)
					continue;

				if(zcache[j][1]!=0)
					zcache[i][1] = zcache[j][1]+num[i];
				else
					zcache[i][1] = num[i]+num[j];

				zcache[j][1] = -1;
				if(result < zcache[i][1])
					result = zcache[i][1];
			}
			else
			{
				int gcdnum = gcd(disx,disy);
				disx/=gcdnum;
				disy/=gcdnum;

				if(ntmp.find(disx)==ntmp.end())
					ntmp.insert(make_pair(disx,unordered_map<int,int>()));

				unordered_map<int, unordered_map<int,int> >::iterator iter=ncache[j].find(disx);
				if(iter==ncache[j].end())
				{
					ntmp[disx].insert(make_pair(disy,num[i]+num[j]));
					if(result < num[i]+num[j])
						result = num[i]+num[j];
				}
				else
				{
					unordered_map<int,int>::iterator it = iter->second.find(disy);
					if(it==iter->second.end())
					{
						ntmp[disx].insert(make_pair(disy,num[i]+num[j]));
						if(result < num[i]+num[j])
							result = num[i]+num[j];
					}
					else
					{
						if(it->second == -1)
							continue;

						ntmp[disx].insert(make_pair(disy,it->second+num[i]));
						if(result < it->second+num[i])
							result = it->second+num[i];
						it->second = -1;
					}
				}
			}
		}
		ncache[i]=ntmp;
	}

	return result;
}

int main()
{
	vector<Point> points(15);
	points[0] = Point(0,-12);
	points[1] = Point(5,2);
	points[2] = Point(2,5);
	points[3] = Point(0,-5);
	points[4] = Point(1,5);
	points[5] = Point(2,-2);
	points[6] = Point(5,-4);
	points[7] = Point(3,4);
	points[8] = Point(-2,4);
	points[9] = Point(-1,4);
	points[10] = Point(0,-5);
	points[11] = Point(0,-8);
	points[12] = Point(-2,-1);
	points[13] = Point(0,-11);
	points[14] = Point(0,-9);

	int result = maxPoints(points);
	cout << result << endl;
	return 0;
}
