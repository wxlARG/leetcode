#include"common.h"
using namespace std;

void getMax_solution1(vector<int>& nums, vector<int>& target, int sz) {
    if(sz==0) return;
    deque<int> l, r;
    for(int i=0; i<sz; ++i) {
        r.push_back(nums[i]);
        if(r.size()>1 && r[0]>=r[1]) {
            l.push_back(r.front());
            r.pop_front();
        }
    }
    for(int i=sz; i<nums.size(); ++i) {
        if(r.size()==1 && r[0]<nums[i]) {
            r[0]=nums[i];
        } else if(r.size()!=1) {
            r.push_back(nums[i]);
            r.pop_front();
        }
        if(!l.empty() && l.back()<r.front()) {
            r.push_front(l.back());
            l.pop_back();
        } else {
            while(r.size()>1 && r[0]>=r[1]) {
                l.push_back(r.front());
                r.pop_front();
            }
        }
    }
    target.insert(target.end(), l.begin(), l.end());
    target.insert(target.end(), r.begin(), r.end());
}

void merge_solution1(vector<int>& nums1, vector<int>& nums2, vector<int>& res) {
    nums1.push_back(-1);
    nums2.push_back(-1);
    for(int pos1=0, pos2=0; nums1[pos1]!=-1 || nums2[pos2]!=-1; ) {
        if(nums1[pos1]<nums2[pos2]) {
            res.push_back(nums2[pos2]);
            ++pos2;
        } else if(nums1[pos1]>nums2[pos2]) {
            res.push_back(nums1[pos1]);
            ++pos1;
        } else {
            int start1=pos1, start2=pos2;
            while(nums1[pos1]!=-1 && nums2[pos2]!=-1 && nums1[pos1]==nums2[pos2]) ++pos1, ++pos2;
            if(nums1[pos1]<nums2[pos2]) {
                pos1=start1, pos2=start2;
                while(nums2[pos2]<=nums2[pos2+1]) res.push_back(nums2[pos2++]);
                res.push_back(nums2[pos2++]);
            } else {
                pos1=start1, pos2=start2;
                while(nums1[pos1]<=nums1[pos1+1]) res.push_back(nums1[pos1++]);
                res.push_back(nums1[pos1++]);
            }
        }
    }
}

void getMax(vector<int>& nums, vector<int>& target, int sz) {
    if(sz==0) return;
    for(int i=0; i<nums.size(); ++i) {
        if(target.size()==sz && nums[i]<=target.back()) continue;
        while(!target.empty() && nums[i]>target.back() && nums.size()-i>sz-target.size()) {
            target.pop_back();
        }
        target.push_back(nums[i]);
    }
}

void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& res) {
    nums1.push_back(-1);
    nums2.push_back(-1);
    for(int i=0, j=0; nums1[i]!=-1 || nums2[j]!=-1; ) {
        if(nums1[i]>nums2[j]) {
            res.push_back(nums1[i++]);
        } else if(nums1[i]<nums2[j]) {
            res.push_back(nums2[j++]);
        } else {
            int ti=i, tj=j;
            for(; nums1[ti]!=-1 || nums2[tj]!=-1; ++ti, ++tj) {
                if(nums1[ti]!=nums2[tj]) break;
            } 
            if(nums1[ti]>nums2[tj]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]); 
        }
    }
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> res(k, 0);
    for(int i=0; i<=k; ++i) {
        if(i>nums1.size() || k-i<0 || k-i>nums2.size()) continue;
        vector<int> up, down, tres;
        getMax(nums1, up, i);
        getMax(nums2, down, k-i);
        merge(up, down, tres);
        if(tres>res) res.swap(tres);
    }
    return res;
}

int main() {
    //vector<int> nums1={3, 4, 6, 5};
    //vector<int> nums2={9, 1, 2, 5, 8, 3};
    //auto res=maxNumber(nums1, nums2, 5);
    vector<int> nums1={5,2,2};
    vector<int> nums2={6,4,1};
    auto res=maxNumber(nums1, nums2, 3);
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
