#include"common.h"
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) board[i][j]<<=1;
    }
    vector<int> xd({-1, 0, 1}), yd({-1, 0, 1});
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) {
            int num=0;
            for(auto x: xd) {
                for(auto y: yd) {
                    if(x==0 && y==0) continue;
                    if(i+x>=0 && i+x<board.size() && j+y>=0 && j+y<board[0].size() && (board[i+x][j+y]&2)) ++num;
                }
            }
            if(num==2 && (board[i][j]&2)!=0) board[i][j]|=1;
            if(num==3) board[i][j]|=1;
        }
    }
    for(int i=0; i<board.size(); ++i) {
        for(int j=0; j<board[i].size(); ++j) board[i][j] &= 1;
    }
}

int main() {
    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    gameOfLife(board);
    for(auto &vec: board) {
        for(auto& v: vec) cout << v << "\t";
        cout << endl;
    }
}
