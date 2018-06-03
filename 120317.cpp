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

void swap(vector<vector<int> > &matrix, int n, int row, int col)
{
	int cache = matrix[row][col];

	for(int i=0; i<4; ++i)
	{
		int tmp = row;
		row = col;
		col = n-1-tmp;
		tmp = matrix[row][col];
		matrix[row][col] = cache;
		cache = tmp;
	}
}

void rotate(vector<vector<int> > &matrix) 
{
	int size = matrix.size();
	int col = (size-1)/2;
	int row = col;
	if(size % 2 != 0)
		row = col-1;

	for(int i=0; i<=row; ++i)
		for(int j=0; j<=col; ++j)
			swap(matrix,size,i,j);
}

int main()
{
	vector<vector<int> > matrix;
	int n=4;
	int num = 0;
	for(int i=0; i<n; ++i)
	{
		vector<int> tmp;
		for(int j=0; j<n; ++j)
			tmp.push_back(num++);
		matrix.push_back(tmp);
	}

	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}

	rotate(matrix);

	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}

	return 0;
}
