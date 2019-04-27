#include"common.h"
using namespace std;

void helper(int cur, int n, vector<int>& res) {
    if(cur>n) return;
    res.push_back(cur);
    for(int i=0; i<=9; ++i) helper(cur*10+i, n, res);
}

vector<int> lexicalOrder(int n) {
    vector<int> res;
    for(int i=1; i<=9; ++i) helper(i, n, res);
    return res;
}

int main() {
    auto res=lexicalOrder(13);
    for(auto v: res) cout << v << "\t";
    cout << endl;
}
