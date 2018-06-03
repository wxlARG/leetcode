#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0; i<board.size(); ++i) {
        bool c[9] = {false};
        for(int j=0; j<board[i].size(); ++j) {
            if(board[i][j] == '.') continue;
            if(c[board[i][j]-'1']) return false;
            c[board[i][j]-'1'] = true;
        }
    }

    for(int j=0; j<board[0].size(); ++j) {
        bool c[9] = {false};
        for(int i=0; i<board.size(); ++i) {
            if(board[i][j] == '.') continue;
            if(c[board[i][j]-'1']) return false;
            c[board[i][j]-'1'] = true;
        }
    }

    for(int b=0; b<3; ++b) {
        for(int k=0; k<3; ++k) {
            bool c[9] = {false};
            for(int i=3*b; i<3*(b+1); ++i) {
                for(int j=3*k; j<3*(k+1); ++j) {
                    if(board[i][j] == '.') continue;
                    if(c[board[i][j]-'1']) return false;
                    c[board[i][j]-'1'] = true;
                }
            }
        }
    }
    return true;
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
    cout << isValidSudoku(board) << endl;
}
