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
using namespace std;

int maximalSquare(vector<vector<char> >& matrix)
{
	if(matrix.size() == 0)
		return 0;

	vector<vector<int> > cache(matrix.size(), vector<int>(matrix[0].size(),0));
	vector<int> pos(matrix[0].size(),-1);

	int max = 0;

	for(int i=0; i<matrix.size(); ++i)
	{
		int last = -1;
		for(int j=0; j<matrix[i].size(); ++j)
		{
			if(max<matrix[i][j]-'0')
				max = matrix[i][j]-'0';

			if(matrix[i][j] == '0')
			{
				pos[j] = i;
				last = j;
			}

			if(i==0 || j==0 || matrix[i][j]=='0')
			{
				cache[i][j] = matrix[i][j]-'0';
				continue;
			}

			int tmp = cache[i-1][j-1];
			int len = sqrt(tmp);
			int curlen = min(min(len+1,i-pos[j]),j-last);
			cache[i][j]=curlen*curlen;
			if(max<cache[i][j])
				max=cache[i][j];
		}
	}
	return max;
}

int main()
{
	char arr[][5] = {
		{1,0,1,0,0},
		{1,0,1,1,1},
		{1,1,1,1,1},
		{1,0,0,1,0}
	};

	vector<vector<char> > matrix;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
	{
		vector<char> tmp;
		for(int j=0; j<5; ++j)
			tmp.push_back(arr[i][j]+'0');
		matrix.push_back(tmp);
	}

	int result = maximalSquare(matrix);

	cout << result << endl;
	return 0;
}
