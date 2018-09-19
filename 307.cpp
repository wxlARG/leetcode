#include"common.h"
using namespace std;

class NumArray_solution1 {
public:
    NumArray_solution1(vector<int> nums) {
        len=nums.size();
        if(len==0) return;
        st.resize(pow(2, ceil(log2(len))+1)-1);
        build_tree(nums, 0, 0, len-1);
    }
    
    void update(int i, int val) {
        update_helper(i, val, 0, len-1, 0);
    }
    
    int sumRange(int i, int j) {
        return sum_helper(i, j, 0, len-1, 0);
    }
private:
    int len;
    vector<int> st;
    void build_tree(vector<int>& nums, int pos, int start, int end) {
        if(start==end) {
            st[pos]=nums[start];
            return;
        }
        int mid=start+(end-start)/2;
        build_tree(nums, 2*pos+1, start, mid);
        build_tree(nums, 2*pos+2, mid+1, end);
        st[pos]=st[2*pos+1]+st[2*pos+2];
    }

    int update_helper(int i, int val, int start, int end, int pos) {
        if(start==end) {
            int v=st[pos];
            st[pos]=val;
            return v;
        }
        int mid=start+(end-start)/2, ns=start, ne=end, np=pos;
        if(i<=mid) {
            ne=mid;
            np=2*pos+1;
        } else {
            ns=mid+1;
            np=2*pos+2;
        }
        int pr=update_helper(i, val, ns, ne, np);
        st[pos]=st[pos]-pr+val;
        return pr;
    }

    int sum_helper(int i, int j, int start, int end, int pos) {
        if(end<i || start>j) return 0;
        if(start>=i && end<=j) return st[pos];
        int mid=start+(end-start)/2;
        return sum_helper(i, j, start, mid, 2*pos+1)+sum_helper(i, j, mid+1, end, 2*pos+2);
    }
};

class NumArray {
public:
    NumArray(vector<int> nums): bt(nums.size()+1, 0), ns(nums.size(), 0) {
        for(int i=0; i<nums.size(); ++i) update(i, nums[i]);
    }
    
    void update(int i, int val) {
        int diff=val-ns[i];
        ns[i]=val;
        for(int pos=i+1; pos<bt.size(); pos+=pos&-pos) bt[pos]+=diff;
    }
    
    int sumRange(int i, int j) {
        int first=0, second=0;
        for(int pos=i; pos!=0; pos-=pos&-pos) first+=bt[pos];
        for(int pos=j+1; pos!=0; pos-=pos&-pos) second+=bt[pos];
        return second-first;
    }
private:
    vector<int> bt;
    vector<int> ns;
};

int main() {
    NumArray obj({-28,-39,53,65,11,-56,-65,-39,-43,97});
    cout << obj.sumRange(5, 6) << endl;
	obj.update(9, 27);
    cout << obj.sumRange(2, 3) << endl;
}
