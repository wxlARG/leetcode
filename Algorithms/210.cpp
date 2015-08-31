#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

bool dfs(int pos, vector<vector<int> >& cache, vector<char>& color, vector<int>& result)
{
	color[pos] = 1;
	for(int i=0; i<cache[pos].size(); ++i)
	{
		bool tmp = true;
		if(color[cache[pos][i]] == 0)
			tmp = dfs(cache[pos][i],cache,color,result);

		if(tmp == false || color[cache[pos][i]] == 1)
			return false;
	}

	color[pos] = 2;
	result.push_back(pos);
	return true;
}

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites)
{
	vector<int> result;
	vector<vector<int> > cache(numCourses);
	vector<char> color(numCourses,0);
	for(int i=0; i<prerequisites.size(); ++i)
		cache[prerequisites[i].first].push_back(prerequisites[i].second);

	for(int i=0; i<numCourses; ++i)
		if(color[i] == 0)
		{
			bool tmp = dfs(i,cache,color,result);
			if(!tmp)
				return vector<int>();
		}

	return result;
}

int main()
{

	int arr[][2] = {
		{1,0},
		{2,0},
		{3,1},
		{3,2}
	};

	vector<pair<int,int> > prerequisites;

	for(int i=0; i<4; ++i)
		prerequisites.push_back(make_pair(arr[i][0],arr[i][1]));

	vector<int> result = findOrder(4,prerequisites);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
