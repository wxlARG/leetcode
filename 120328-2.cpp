#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
	if(grid.size()==0)
		return 0;

	vector<int> cache(grid[0]);
	for(int j=1; j<grid[0].size(); ++j)
		cache[j] += cache[j-1];

	for(int i=1; i<grid.size(); ++i)
		for(int j=0; j<grid[i].size(); ++j)
			if(j == 0)
				cache[j] += grid[i][j];
			else
				cache[j] = min(cache[j-1],cache[j])+grid[i][j];

	return cache[grid[0].size()-1];
}

int main()
{
	int arr[][3] = {
		{1,2,3},
		{4,5,6},
	};

	vector<vector<int> > grid;

	for(int i=0; i<2; ++i)
	{
		vector<int> tmp;
		for(int j=0; j<3; ++j)
			tmp.push_back(arr[i][j]);
		grid.push_back(tmp);
	}

	int result = minPathSum(grid);
	cout << result << endl;
	return 0;
}
