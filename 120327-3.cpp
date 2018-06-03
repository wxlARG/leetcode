#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

vector<vector<int> > generateMatrix(int n)
{
	vector<vector<int> > result(n);

	for(int i=0; i<result.size(); ++i)
	{
		vector<int> tmp(n);
		result[i] = tmp;
	}

	int srow = 0;
	int erow = n-1;

	if(srow > erow)
		return result;

	int scol = 0;
	int ecol = n-1;

	int num = 1;
	while(1)
	{
		if(srow>erow || scol > ecol)
			break;

		for(int i=scol; i<=ecol; ++i)
			result[srow][i] = num++;
		++srow;

		if(srow>erow || scol > ecol)
			break;

		for(int i=srow; i<=erow; ++i)
			result[i][ecol] = num++;
		--ecol;

		if(srow>erow || scol > ecol)
			break;

		for(int i=ecol; i>=scol; --i)
			result[erow][i] = num++;
		--erow;

		if(srow>erow || scol > ecol)
			break;

		for(int i=erow; i>=srow; --i)
			result[i][scol] = num++;
		++scol;
	}

	return result;
}

int main()
{
	vector<vector<int> > result = generateMatrix(3);

	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}

	return 0;
}
