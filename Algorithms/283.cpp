#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int z=0;
    for(int i=0; i<nums.size(); ++i)
    {
        if(nums[i]!=0 && nums[z]==0)
            swap(nums[i],nums[z++]);
        else if(nums[z]!=0)
            ++z;
    }
}

int main()
{
    int a[] = {0, 1, 0, 3, 12};
    vector<int> nums;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

    moveZeroes(nums);
    for(int i=0; i<nums.size(); ++i)
        cout << nums[i] << endl;
    return 0;
}
