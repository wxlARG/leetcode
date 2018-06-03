#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

bool helper_solution1(int x, int y, int pos, string& word, vector<vector<char>>& board, vector<vector<bool>>& flags) {
    if(pos==word.size()) return true;
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(auto &p: d) {
        int nx=x+p.first, ny=y+p.second;
        if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size()) continue;
        if(board[nx][ny]==word[pos] && !flags[nx][ny]) {
            flags[nx][ny] = true;
            if(helper_solution1(nx, ny, pos+1, word, board, flags)) return true;
            flags[nx][ny] = false;
        }
    }
    return false;
}

bool exist_solution1(vector<vector<char>>& board, string word) {
    vector<pair<int, int>> starts;
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) {
            if(board[i][j]==word[0]) starts.push_back({i, j});
        }
    }
    if(starts.size()==0) return false;
    vector<vector<bool>> flags(board.size(), vector<bool>(board[0].size(), false));
    for(auto &p: starts) {
        flags[p.first][p.second] = true;
        if(helper_solution1(p.first, p.second, 1, word, board, flags)) return true;
        flags[p.first][p.second] = false;
    }
    return false;
}

bool helper(int x, int y, int pos, string& word, vector<vector<char>>& board) {
    if(board[x][y]!=word[pos]) return false;
    if(pos==word.size()-1) return true;
    board[x][y] = 0;
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(auto &p: d) {
        int nx=x+p.first, ny=y+p.second;
        if(nx<0 || nx>=board.size() || ny<0 || ny>=board[0].size()) continue;
        if(helper(nx, ny, pos+1, word, board)) return true;
    }
    board[x][y] = word[pos];
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) {
            if(helper(i, j, 0, word, board)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << exist(board, "ABCB") << endl;
}
