#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

class NumArray {
    public:
        NumArray(vector<int> &nums){
            sums.push_back(0);
            for(int i=0; i<nums.size(); ++i)
                sums.push_back(sums.back()+nums[i]);
        }

        int sumRange(int i, int j) {
            return sums[j+1] - sums[i];
        }
    private:
        vector<int> sums;
};

int main()
{
    int a[] = {-2, 0, 3, -5, 2, -1};
    vector<int> nums;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    cout << numArray.sumRange(1, 2) << endl;
    return 0;
}
