#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int helper(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int pos) {
    if(end1 - start1 > end2 - start2)
        return helper(nums2, nums1, start2, end2, start1, end1, pos);  
    if(start1 >= end1)
        return nums2[pos];
    if(pos == 0)
        return min(nums1[start1], nums2[start2]);
    int pos1 = min((pos-1)/2, end1-1);
    int pos2 = pos - 1 - pos1;
    if(nums1[start1 + pos1] <= nums2[start2 + pos2])
        return helper(nums1, nums2, start1+pos1+1, end1, start2, end2, pos-pos1-1);
    else
        return helper(nums1, nums2, start1, end1, start2+pos2+1, end2, pos-pos2-1);
}

double findMedianSortedArrays_solution1(vector<int>& nums1, vector<int>& nums2) {
    if((nums1.size() + nums2.size()) % 2 != 0) {
        return helper(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (nums1.size() + nums2.size())/2);
    }
    double res1 = helper(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (nums1.size() + nums2.size())/2-1);
    double res2 = helper(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (nums1.size() + nums2.size())/2);
    return (res1+res2)/2;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);
    nums1.push_back(INT_MAX);
    nums2.push_back(INT_MAX);
    int tl = nums1.size() + nums2.size()-2;
    int t = ((tl & 1) ? (tl+1)>>1 : tl>>1) - 2;
    int start=-1, end=nums1.size()-1, k=0, j=0;
    while(start<=end) {
        k=start+(end-start)/2;
        j = t-k;
        int k1=INT_MIN, j1=INT_MIN;
        if(k!=-1) k1=nums1[k];
        if(j!=-1) j1=nums2[j];
        if(k1<=nums2[j+1] && j1<=nums1[k+1])
            return (tl & 1) ? max(k1, j1) : (max(k1, j1)+min(nums1[k+1], nums2[j+1]))/2.0;
        else if(k1>nums2[j+1])
            end = k-1;
        else 
            start = k+1;
    }
    return 0;
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2};
    //auto res = findMedianSortedArrays_solution2(nums1, nums2);
    auto res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}
