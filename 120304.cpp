#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

bool solve(vector<vector<char> >& board, vector<vector<char> >& row, vector<vector<char> >& col, vector<vector<char> >& block)
{
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
		{
			if(board[i][j] != '.')
				continue;

			int pos = i/3*3 + j/3;
			vector<char> possible(9,0);

			int zeronum = 9;

			for(int k=0; k<9; ++k)
			{
				if(row[i][k]!=0 && possible[k] == 0)
				{
					--zeronum;
					possible[k] = 1;
				}
				if(col[j][k]!=0 && possible[k] == 0)
				{
					--zeronum;
					possible[k] = 1;
				}
				if(block[pos][k]!=0 && possible[k] == 0)
				{
					--zeronum;
					possible[k] = 1;
				}
			}

			if(zeronum == 0)
				return false;

			for(int k=0; k<9; ++k)
			{
				if(possible[k])
					continue;
				row[i][k] = 1;
				col[j][k] = 1;
				block[pos][k] = 1;
				board[i][j] = k+1+'0';

				if(solve(board, row, col, block))
					return true;

				row[i][k] = 0;
				col[j][k] = 0;
				block[pos][k] = 0;
				board[i][j] = '.';
			}
			return false;
		}
	}

	return true;
}

void solveSudoku(vector<vector<char> > &board)
{
	vector<vector<char> > row;
	vector<vector<char> > col;
	vector<vector<char> > block;

	for(int i=0; i<9; ++i)
	{
		vector<char> tmp(9,0);
		row.push_back(tmp);
		col.push_back(tmp);
		block.push_back(tmp);
	}

	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
		{
			if(board[i][j] == '.')
				continue;

			int val = board[i][j] - '0' -1;
			row[i][val] = 1;
			col[j][val] = 1;
			int pos = i/3*3 + j/3;
			block[pos][val] = 1;
		}
	}

	solve(board, row, col, block);
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

	solveSudoku(board);
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
			cout << board[i][j] << "\t";
		cout << endl;
	}

	return 0;
}
