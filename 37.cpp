#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool helper(vector<vector<char>>& board) {
    int posx=-1, posy=-1;
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) {
            if(board[i][j] == '.') {
                posx=i;
                posy=j;
                break;
            }
        }
        if(posx!=-1) break;
    }

    if(posx==-1) 
        return true;
    vector<bool> c(9, false);
    for(int j=0; j<board[0].size(); ++j) {
        if(board[posx][j]=='.') continue;
        c[board[posx][j]-'1'] = true;
    }

    for(int i=0; i<board.size(); ++i) {
        if(board[i][posy]=='.') continue;
        c[board[i][posy]-'1'] = true;
    }

    for(int i=posx/3*3; i<(posx+3)/3*3; ++i) {
        for(int j=posy/3*3; j<(posy+3)/3*3; ++j) {
            if(board[i][j]=='.') continue;
            c[board[i][j]-'1'] = true;
        }
    }

    for(int i=0; i<9; ++i) {
        if(c[i] == false) {
            board[posx][posy] = '1'+i;
            if(helper(board)) 
                return true;
            board[posx][posy] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board);
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board);
    for(auto &v: board) {
        for(auto &c: v) 
            cout << c << "\t";
        cout << endl;
    }
}
