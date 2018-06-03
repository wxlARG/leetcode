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

void bfs(vector<vector<char> > &board, int x, int y)
{
	deque<vector<int> > queue;
	vector<int> point(2);
	vector<vector<int> > cache;
	bool flag=0;

	point[0]=x;
	point[1]=y;
	queue.push_back(point);

	while(!queue.empty())
	{
		vector<int> tmp = queue.front();
		queue.pop_front();

		if(!flag)
			cache.push_back(tmp);

		x=tmp[0];
		y=tmp[1];

		board[x][y] = flag;

		for(int i=-1; i<=1; ++i)
			for(int j=-1; j<=1; ++j)
				if(i!=0 && j!=0)
					continue;
				else if(x+i>=0 && x+i<board.size() && y+j>=0 && y+j<board[0].size())
				{
					if(board[x+i][y+j] == 'O')
					{
						board[x+i][y+j] = flag;
						point[0] = x+i;
						point[1] = y+j;
						queue.push_back(point);
					}
				}
				else
				{
					if(!flag)
					{
						flag = 1;
						for(int k=0; k<cache.size(); ++k)
							board[cache[k][0]][cache[k][1]] = flag;
						cache.clear();
					}
				}
	}
}

void solve(vector<vector<char> > &board)
{
	for(int i=0; i<board.size(); ++i)
		for(int j=0; j<board[i].size(); ++j)
			if(board[i][j]=='O')
				bfs(board,i,j);

	for(int i=0; i<board.size(); ++i)
		for(int j=0; j<board[i].size(); ++j)
			if(board[i][j] == 1)
				board[i][j] = 'O';
			else
				board[i][j] = 'X';
}

int main()
{
	int arr[][4] = {
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'}
	};

	vector<vector<char> > board;
	for(int i=0; i<4; ++i)
	{
		vector<char> tmp;
		for(int j=0; j<4; ++j)
			tmp.push_back(arr[i][j]);
		board.push_back(tmp);
	}

	solve(board);

	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
			cout << board[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
