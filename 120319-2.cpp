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

bool issamecol(deque<int>& cache, int col)
{
	for(int i=0; i<cache.size(); ++i)
		if(cache[i] == col)
			return true;
	return false;
}

bool issameline(deque<int>& cache, int row, int col)
{
	for(int i=0; i<cache.size(); ++i)
		if((i-row == cache[i]-col) || (row-i == cache[i]-col))
			return true;
	return false;
}

void func(vector<vector<string> >& result, deque<int>& cache, int row, int n)
{
	if(row == n)
	{
		vector<string> tmp(n,string(n,'.'));
		for(int i=0; i<n; ++i)
			tmp[i][cache[i]] = 'Q';
		result.push_back(tmp);
	}

	for(int i=0; i<n; ++i)
	{
		if(!(issamecol(cache,i) || issameline(cache,row,i)))
		{
			cache.push_back(i);
			func(result,cache,row+1,n);
			cache.pop_back();
		}
	}
}

vector<vector<string> > solveNQueens(int n)
{
	vector<vector<string> > result;
	deque<int> cache;
	func(result,cache,0,n);
	return result;
}

int main()
{
	vector<vector<string> > result = solveNQueens(4);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << endl;
		cout << endl;
	}
	return 0;
}
