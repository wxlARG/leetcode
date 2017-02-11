#include<iostream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void wiggleSort(vector<int>& nums)
{
    int n=nums.size();
    nth_element(nums.begin(), nums.begin()+n/2, nums.end());
    int midval = nums[n/2];

    if(n%2==0)
        ++n;

#define A(x) nums[(2*x+1)%n]

    int i=0, j=0, k=nums.size()-1;
    while(j<=k)
        if(A(j)<midval)
            swap(A(j), A(k--));
        else if (A(j)>midval)
            swap(A(i++), A(j++));
        else 
            ++j;
}

int main()
{
    vector<int> nums {1,2,1,2,1,1,2,2,1};
    wiggleSort(nums);
    for(auto num:nums)
        cout << num << "\t";
    cout << endl;
    return 0;
}
