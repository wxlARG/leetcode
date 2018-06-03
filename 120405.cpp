#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

void setZeroes(vector<vector<int> > &matrix)
{
	int row = -1;
	for(int i=0; i<matrix.size(); ++i)
	{
		int flag = 0;
		for(int j=0; j<matrix[i].size(); ++j)
		{
			if(matrix[i][j] == 0)
			{
				flag = 1;
				if(row == -1)
					row = i;
				matrix[row][j] = 0;
			}
		}

		if(flag == 1 && row != i)
			for(int j=0; j<matrix[i].size(); ++j)
				matrix[i][j] = 0;
	}

	if(row != -1)
	{
		for(int j=0; j<matrix[row].size(); ++j)
		{
			if(matrix[row][j] == 0)
				for(int i=0; i<matrix.size(); ++i)
					matrix[i][j] = 0;
			else
				matrix[row][j] = 0;
		}
	}
}

int main()
{
	int arr[][1] = {
		{2147483647},
		{2},
		{3}
	};

	vector<vector<int> > matrix;
	for(int i=0; i<3; ++i)
	{
		vector<int> tmp;
		for(int j=0; j<1; ++j)
			tmp.push_back(arr[i][j]);
		matrix.push_back(tmp);
	}

	setZeroes(matrix);

	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<1; ++j)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
