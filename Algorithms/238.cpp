#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> result(nums.size(),1);
    int tmp=nums.back();
    for(int i=nums.size()-2; i>=0; --i)
    {
        result[i] = tmp;
        tmp *= nums[i];
    }

    tmp=nums[0];
    for(int i=1; i<nums.size(); ++i)
    {
        result[i]*=tmp;
        tmp*=nums[i];
    }
    return result;
}

int main()
{
    int arr[] = {1,2,3,4};
    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
        nums.push_back(arr[i]);

    vector<int> result = productExceptSelf(nums);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;

    return 0;
}
