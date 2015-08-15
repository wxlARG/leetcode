#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
{
	if(obstacleGrid.size()==0)
		return 0;

	vector<int> cache(obstacleGrid[0].size(),0);
	for(int j=0; j<obstacleGrid[0].size(); ++j)
		if(obstacleGrid[0][j] == 1)
			cache[j] = 0;
		else if(j==0)
			cache[j] = 1;
		else
			cache[j] = cache[j-1];

	for(int i=1; i<obstacleGrid.size(); ++i)
		for(int j=0; j<obstacleGrid[0].size(); ++j)
			if(obstacleGrid[i][j] == 1)
				cache[j] = 0;
			else if(j>0)
				cache[j] += cache[j-1];

	return cache[obstacleGrid[0].size()-1];
}

int main()
{
	int arr[][1] = {
		{0},
		{1},
	};

	vector<vector<int> > obstacleGrid;

	for(int i=0; i<2; ++i)
	{
		vector<int> tmp;
		for(int j=0; j<1; ++j)
			tmp.push_back(arr[i][j]);
		obstacleGrid.push_back(tmp);
	}

	int result = uniquePathsWithObstacles(obstacleGrid);
	cout << result << endl;
	return 0;
}
