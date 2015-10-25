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

int findDuplicate(vector<int>& nums)
{
    int start=1, end=nums.size()-1;
    while(start<end)
    {
        int mid = start+(end-start)/2;
        int target = mid;
        cout << mid << "\t" << target << endl;
        int tmp=0;
        for(int i=0; i<nums.size(); ++i)
            if(nums[i]<=mid)
                ++tmp;
        if(tmp > target)
            end = mid; 
        else
            start = mid+1;
    }
    return start;
}

int main()
{
    int a[] = {1,4,4,2,4};
    vector<int> nums;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        nums.push_back(a[i]);

    int result = findDuplicate(nums);
    cout << result << endl;
    return 0;
}
