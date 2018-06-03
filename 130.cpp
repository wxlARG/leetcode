#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include"common.h"
using namespace std;

void dfs(int x, int y, vector<vector<char>>& board) {
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size()) return;
    if(board[x][y]=='X' || board[x][y]=='T') return;
    board[x][y]='T';
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(auto d: dirs) dfs(x+d.first, y+d.second, board);
}

void solve(vector<vector<char>>& board) {
    if(board.size()==0) return;
    for(int i=0; i<board.size(); ++i) {
        dfs(i, 0, board);
        dfs(i, board[0].size()-1, board);
    }
    for(int j=0; j<board[0].size(); ++j) {
        dfs(0, j, board);
        dfs(board.size()-1, j, board);
    }
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) {
            if(board[i][j]=='T') board[i][j]='O';
            else if(board[i][j]=='O') board[i][j]='X';
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
    };
    solve(board);
    for(auto &v: board) {
        for(auto &c: v) cout << c << "\t";
        cout << endl;
    }
}
