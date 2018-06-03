#include"common.h"
using namespace std;

int singleNumber(vector<int>& nums) {
    vector<vector<int>> cache(32, vector<int>(2, 0));
    for(auto &v: nums) {
        for(int i=0; i<32; ++i) {
            if((v & (1<<i))!=0) ++cache[i][1];
            else ++cache[i][0];
        }
    }
    int res=0;
    for(int i=0; i<32; ++i) if(cache[i][1]%3!=0) res |= (1<<i);
    return res;
}

int main() {
    vector<int> nums ={2, 2, 2, 3, 3, 1, 3};
    cout << singleNumber(nums) << endl;
}
