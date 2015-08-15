#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
#include<time.h>
using namespace std;

void func(vector<vector<int> >& result, vector<int>& cache, int k, int n, int start)
{
	if(k==0)
	{
		if(n==0)
			result.push_back(cache);
		return;
	}

	int end = min(n/k,9);

	for(int i=start; i<=end; ++i)
	{
		cache.push_back(i);
		func(result,cache,k-1, n-i,i+1);
		cache.pop_back();
	}
}

vector<vector<int> > combinationSum3(int k, int n)
{
	vector<vector<int> > result;
	vector<int> cache;

	func(result,cache,k,n,1);

	return result;
}

int main()
{
	vector<vector<int> > result = combinationSum3(2,18);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
