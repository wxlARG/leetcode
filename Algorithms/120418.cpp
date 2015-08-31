#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

bool func(vector<vector<char> > &board, string& word, int i, int j, int next)
{
	if(next == word.size())
		return true;

	int row = board.size();
	int col = board[0].size();

	if(i+1<row && board[i+1][j]==word[next])
	{
		board[i+1][j] = 0;
		bool flag = func(board,word,i+1,j,next+1);
		board[i+1][j] = word[next];
		if(flag)
			return true;
	}

	if(i-1>=0 && board[i-1][j]==word[next])
	{
		board[i-1][j] = 0;
		bool flag = func(board,word,i-1,j,next+1);
		board[i-1][j] = word[next];
		if(flag)
			return true;
	}

	if(j+1<col && board[i][j+1]==word[next])
	{
		board[i][j+1] = 0;
		bool flag = func(board,word,i,j+1,next+1);
		board[i][j+1] = word[next];
		if(flag)
			return true;
	}

	if(j-1>=0 && board[i][j-1]==word[next])
	{
		board[i][j-1] = 0;
		bool flag = func(board,word,i,j-1,next+1);
		board[i][j-1] = word[next];
		if(flag)
			return true;
	}

	return false;
}

bool exist(vector<vector<char> > &board, string word)
{
	int row = board.size();
	int col = board[0].size();

	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			if(board[i][j] == word[0])
			{
				board[i][j] = 0;
				bool flag = func(board,word,i,j,1);
				board[i][j] = word[0];
				if(flag)
					return true;
			}
		}
	}

	return false;
}

int main()
{
	char arr[][4] = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};

	vector<vector<char> > board;
	for(int i=0; i<3; ++i)
	{
		vector<char> tmp;
		for(int j=0; j<4; ++j)
			tmp.push_back(arr[i][j]);
		board.push_back(tmp);
	}

	bool result = exist(board,string("ABCB"));
	cout << result << endl;
	return 0;
}
