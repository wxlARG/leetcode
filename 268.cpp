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

int missingNumber(vector<int>& nums)
{
    for(int i=0; i<nums.size(); ++i)
        while(nums[i]!=i && nums[i]<nums.size())
            swap(nums[i],nums[nums[i]]);

    for(int i=0; i<nums.size(); ++i)
        if(nums[i]!=i)
            return i;
    return nums.size();
}

int main()
{
    int a[] = {0,1,3};
    vector<int> nums;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

    int result = missingNumber(nums);
    cout << result << endl;
    return 0;
}
