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

void func(int& result, deque<int>& cache, int row, int n)
{
	if(row == n)
	{
		result += 1;
		return;
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

int totalNQueens(int n)
{
	int result = 0;
	deque<int> cache;
	func(result,cache,0,n);
	return result;
}

int main()
{
	int result = totalNQueens(4);
	cout << result << endl;
	return 0;
}
