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

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > result;

	for(int i=0; i<numRows; ++i)
	{
		vector<int> tmp(i+1,1);
		for(int j=1; j<i; ++j)
			tmp[j] = result.back()[j-1] + result.back()[j];
		result.push_back(tmp);
	}

	return result;
}

int main()
{
	vector<vector<int> > result = generate(5);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
