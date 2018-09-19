#include"common.h"
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums): sums({0}) {
        for(auto& v: nums) sums.push_back(sums.back()+v);
    }
    
    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
private:
    vector<int> sums;
};

int main() {
    NumArray obj({-2, 0, 3, -5, 2, -1});
    cout << obj.sumRange(0, 2) << endl;
    cout << obj.sumRange(2, 5) << endl;
}
