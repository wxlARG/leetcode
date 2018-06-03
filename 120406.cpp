#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	int start = 0;
	int end = matrix.size()-1;
	int row;

	while(start <= end)
	{
		int mid = start+(end-start)/2;
		if(matrix[mid][0] > target)
			end = mid-1;
		else if(matrix[mid][0] < target)
		{
			if(mid<matrix.size()-1 && matrix[mid+1][0]>target)
			{
				row = mid;
				break;
			}
			else
				start = mid+1;
		}
		else
			return true;
	}

	if(end < 0)
		return false;

	if(start > matrix.size()-1)
		row = matrix.size()-1;

	start = 0;
	end = matrix[row].size()-1;

	while(start <= end)
	{
		int mid = start+(end-start)/2;
		if(matrix[row][mid] > target)
			end = mid-1;
		else if(matrix[row][mid] < target)
			start = mid+1;
		else 
			return true;
	}
	return false;
}

int main()
{
	int arr[][4] = {
		{1,   3,  5,  7},
		{10, 11, 16, 20},
		{23, 30, 34, 50}
	};

	vector<vector<int> > matrix;
	for(int i=0; i<3; ++i)
	{
		vector<int> tmp;
		for(int j=0; j<4; ++j)
			tmp.push_back(arr[i][j]);
		matrix.push_back(tmp);
	}

	bool result = searchMatrix(matrix,8);

	cout << result << endl;
	return 0;
}
