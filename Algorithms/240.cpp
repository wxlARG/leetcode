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

bool func(vector<vector<int> >& matrix, int target, int xstart, int xend, int ystart, int yend)
{
    if(xstart>xend || ystart>yend)
        return 0;

    int x=xstart,y=ystart;
    while(x<=xend && y<=yend && matrix[x][y]<target)
    {
        ++x;
        ++y;
    }

    if(x>xend)
        return func(matrix,target,xstart,xend,y,yend);

    if(y>yend)
        return func(matrix,target,x,xend,ystart,yend);

    if(matrix[x][y] == target)
        return 1;
    else
        return func(matrix,target,x,xend,ystart,y-1) || func(matrix,target,xstart,x-1,y,yend);
}

bool searchMatrix(vector<vector<int> >& matrix, int target)
{
    return func(matrix,target,0,matrix.size()-1,0,matrix[0].size()-1);
}

int main()
{
	int arr[][5] = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    vector<vector<int> > matrix;

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
	{
		vector<int> tmp;
		for(int j=0; j<5; ++j)
			tmp.push_back(arr[i][j]);
		matrix.push_back(tmp);
	}

	bool result = searchMatrix(matrix, 20);

	cout << result << endl;
	return 0;
}
