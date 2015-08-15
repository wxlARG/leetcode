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

int maximalRectangle(vector<vector<char> > &matrix)
{
	int row = matrix.size();
	if(row == 0)
		return 0;

	int col = matrix[0].size();

	int max = 0;

	int** arr = new int*[row];
	for(int i=0; i<row; ++i)
	{
		int* tmp = new int [col] ();
		arr[i] = tmp;
	}

	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			if(matrix[i][j] == 0 + '0')
			{
				arr[i][j] = 0;
				continue;
			}

			int lastVal = 0;
			if(j > 0)
				lastVal = arr[i][j-1];
			
			arr[i][j] = lastVal+1;
			int colMin = arr[i][j];
			for(int k=i; k>=0 && arr[k][j]!=0; --k)
			{
				if(colMin > arr[k][j])
					colMin = arr[k][j];
				int maxTmp = colMin*(i-k+1);
				if(maxTmp > max)
					max = maxTmp;
			}
		}
	}

	for(int i=0; i<row; ++i)
		delete [] arr[i];
	delete arr;

	return max;
}

int main()
{
/*	char arr[4][5] = {
		{1,1,1,1,1},
		{1,0,1,1,1},
		{1,1,1,0,1},
		{1,1,1,1,1},
	};*/

	char arr[1][1] = {
		{0},
	};

	vector<vector<char> > matrix;

	for(int i=0; i<1; ++i)
	{
		vector<char> tmp;
		for(int j=0; j<1; ++j)
			tmp.push_back(arr[i][j]);
		matrix.push_back(tmp);
	}

	int result = maximalRectangle(matrix);
	cout << result << endl;
	return 0;
}
