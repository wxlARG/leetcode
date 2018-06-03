#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos=m+n-1;
    for(int pos1=m-1, pos2=n-1; pos1>=0 || pos2>=0; --pos) {
        int n1 = (pos1>=0? nums1[pos1]: INT_MIN);
        int n2 = (pos2>=0? nums2[pos2]: INT_MIN);
        if(n1<n2) {
            nums1[pos] = n2;
            --pos2;
        } else {
            nums1[pos] = n1;
            --pos1;
        }
    }
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4};
    int m=nums1.size(), n=nums2.size();
    nums1.resize(nums1.size()+nums2.size());
    merge(nums1, m, nums2, n);
    for(auto &v: nums1) {
        cout << v << "\t";
    }
    cout << endl;
}
