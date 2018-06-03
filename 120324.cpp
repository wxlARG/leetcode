#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix)
{
	vector<int> result;
	int srow = 0;
	int erow = matrix.size()-1;

	if(srow > erow)
		return result;

	int scol = 0;
	int ecol = matrix[0].size()-1;

	while(1)
	{
		if(srow>erow || scol > ecol)
			break;

		for(int i=scol; i<=ecol; ++i)
			result.push_back(matrix[srow][i]);
		++srow;

		if(srow>erow || scol > ecol)
			break;

		for(int i=srow; i<=erow; ++i)
			result.push_back(matrix[i][ecol]);
		--ecol;

		if(srow>erow || scol > ecol)
			break;

		for(int i=ecol; i>=scol; --i)
			result.push_back(matrix[erow][i]);
		--erow;

		if(srow>erow || scol > ecol)
			break;

		for(int i=erow; i>=srow; --i)
			result.push_back(matrix[i][scol]);
		++scol;
	}

	return result;
}

int main()
{
	int arr[][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	vector<vector<int> > matrix;

	for(int i=0; i<3; ++i)
	{
		vector<int> tmp;
		for(int j=0; j<3; ++j)
			tmp.push_back(arr[i][j]);
		matrix.push_back(tmp);
	}

	vector<int> result = spiralOrder(matrix);

	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;

	return 0;
}
