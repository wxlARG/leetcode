#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
#include<time.h>
#include<set>
using namespace std;

struct Node
{
	int pos;
	int height;
	Node(int x=0, int y=0):pos(x), height(y){};
};

struct cmp
{
	bool operator () (Node &n1, Node &n2)
	{
		if(n1.height == n2.height)
			return n1.pos < n2.pos;

		return n1.height < n2.height;
	}
};

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings)
{
	vector<pair<int, int> > result;
	priority_queue<Node, vector<Node>, cmp> heap;

	int i=0;
	while(i<buildings.size())
	{
		if(heap.empty() || buildings[i][0]<=heap.top().pos)
		{
			heap.push(Node(buildings[i][1],buildings[i][2]));
			if(result.empty() || buildings[i][2]>result.back().second)
				result.push_back(make_pair(buildings[i][0],buildings[i][2]));
			++i;
		}
		else
		{
			Node tmp = heap.top();
			heap.pop();
			while(!heap.empty() && heap.top().pos<=tmp.pos)
				heap.pop();
			if(heap.empty())
				result.push_back(make_pair(tmp.pos,0));
			else
				result.push_back(make_pair(tmp.pos,heap.top().height));
		}
	}

	while(!heap.empty())
	{
		Node tmp = heap.top();
		heap.pop();
		while(!heap.empty() && heap.top().pos<=tmp.pos)
			heap.pop();
		if(heap.empty())
			result.push_back(make_pair(tmp.pos,0));
		else
			result.push_back(make_pair(tmp.pos,heap.top().height));
	}
	return result;
}

int main()
{
	int arr[][3] = {
/*		{2,9,10},
		{3,7,15},
		{5,12,12},
		{15,20,10},
		{19,24,8}*/
		{1,5,3},
		{1,5,3},
		{1,5,3}
	};
	vector<vector<int> > buildings;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
	{
		vector<int> tmp;
		for(int j=0; j<3; ++j)
			tmp.push_back(arr[i][j]);
		buildings.push_back(tmp);
	}

	vector<pair<int, int> > result = getSkyline(buildings);
	for(int i=0; i<result.size(); ++i)
		cout << result[i].first << "," << result[i].second << endl;
	return 0;
}
