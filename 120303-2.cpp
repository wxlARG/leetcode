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

bool isValidSudoku(vector<vector<char> > &board)
{
	vector<vector<char> > col;
	vector<vector<char> > block;

	for(int i=0; i<9; ++i)
	{
		vector<char> tmp(9,0);
		col.push_back(tmp);
		block.push_back(tmp);
	}

	for(int i=0; i<board.size(); ++i)
	{
		vector<char> row(9,0);
		for(int j=0; j<9; ++j)
		{
			if(board[i][j] == '.')
				continue;

			int val = board[i][j] - '0' -1;
			if(val<0 || val>8)
				return false;

			if(row[val] != 0)
				return false;
			++row[val];

			if(col[j][val] != 0)
				return false;
			++col[j][val];

			int pos = i/3*3 + j/3;
			if(block[pos][val] != 0)
				return false;
			++block[pos][val];
		}
	}

	return true;
}

int main()
{
	vector<vector<char> > board;
	char sudoku[9][9] = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'},
	};

	for(int i=0; i<9; ++i)
	{
		vector<char> tmp(9);
		for(int j=0; j<9; ++j)
			tmp[j] = sudoku[i][j];
		board.push_back(tmp);
	}

	bool result = isValidSudoku(board);
	cout << result << endl;
	return 0;
}
