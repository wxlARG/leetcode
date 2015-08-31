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

bool dfs(int pos, vector<vector<int> >& cache, vector<char>& color)
{
	color[pos] = 1;
	for(int i=0; i<cache[pos].size(); ++i)
	{
		bool tmp = true;
		if(color[cache[pos][i]] == 0)
			tmp = dfs(cache[pos][i],cache,color);

		if(tmp == false || color[cache[pos][i]] == 1)
			return false;
	}

	color[pos] = 2;
	return true;
}

bool canFinish(int numCourses, vector<vector<int> >& prerequisites)
{
	vector<vector<int> > cache(numCourses);
	vector<char> color(numCourses,0);
	for(int i=0; i<prerequisites.size(); ++i)
		cache[prerequisites[i][0]].push_back(prerequisites[i][1]);

	for(int i=0; i<numCourses; ++i)
		if(color[i] == 0)
		{
			bool tmp = dfs(i,cache,color);
			if(!tmp)
				return false;
		}

	return true;
}

int main()
{

	int arr[][2] = {
		{1,0},
	};

	vector<vector<int> > prerequisites;

	for(int i=0; i<1; ++i)
	{
		vector<int> tmp(2,0);
		for(int j=0; j<2; ++j)
			tmp[j] = arr[i][j];
		prerequisites.push_back(tmp);
	}


	bool result = canFinish(2,prerequisites);
	cout << result << endl;
	return 0;
}
