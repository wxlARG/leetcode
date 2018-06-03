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

void gameOfLife(vector<vector<int>>& board)
{
    for(int i=0; i<board.size(); ++i)
    {
        for(int j=0; j<board[i].size(); ++j)
        {
            int count = 0;
            if(i>0)
            {
                if(j>0 && (board[i-1][j-1]&1)!=0)
                    ++count;
                if((board[i-1][j]&1)!=0)
                    ++count;
                if(j<board[i].size()-1 && (board[i-1][j+1]&1)!=0)
                    ++count;
            }
            if(j>0 && (board[i][j-1]&1)!=0)
                ++count;
            if(j<board[i].size()-1 && (board[i][j+1]&1)!=0)
                ++count;
            if(i<board.size()-1)
            {
                if(j>0 && (board[i+1][j-1]&1)!=0)
                    ++count;
                if((board[i+1][j]&1)!=0)
                    ++count;
                if(j<board[i].size()-1 && (board[i+1][j+1]&1)!=0)
                    ++count;
            }

            if(board[i][j] && count>=2 && count<=3)
                board[i][j] |= (1<<1);
            else if(board[i][j]==0 && count==3)
                board[i][j] |= (1<<1);
        }
    }

    for(int i=0; i<board.size(); ++i)
        for(int j=0; j<board[i].size(); ++j)
            board[i][j] >>= 1;
}

int main()
{
	int arr[][5] = {
        {1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 0}
    };

    vector<vector<int> > board;

    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
	{
		vector<int> tmp;
		for(int j=0; j<5; ++j)
			tmp.push_back(arr[i][j]);
		board.push_back(tmp);
	}

	gameOfLife(board);

    for(int i=0; i<board.size(); ++i)
    {
        for(int j=0; j<board[i].size(); ++j)
            cout << board[i][j] << "\t";
        cout << endl;
    }
	return 0;
}
