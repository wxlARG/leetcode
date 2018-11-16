#include"common.h"
using namespace std;

vector<int> countBits_solution1(int num) {
    vector<int> res(num+1, 0);
    pair<int, int> vals={1, 1};
    for(int i=1; i<=num; ++i) {
        if(i==vals.second) {
            res[i]=1;
            vals.first=vals.second;
            vals.second<<=1;
        } else {
            res[i]=res[i-vals.first]+1;
        }
    }
    return res;
}

vector<int> countBits(int num) {
    vector<int> res(num+1, 0); 
    for(int i=1; i<=num; ++i) res[i]=res[i-(i&-i)]+1;
    return res;
}

int main() {
    auto res=countBits(5);
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
