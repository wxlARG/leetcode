#include"common.h"
using namespace std;

struct Node {
    int count;
    int val;
    Node* left;
    Node* right;
    Node(int v): count(1), val(v), left(NULL), right(NULL) {}
};

int helper_solution1(Node* root, int val) {
    int res=0;
    Node** proot=&root;
    while(*proot!=NULL) {
        ++(*proot)->count;
        if(val<(*proot)->val) {
            proot=&((*proot)->left);
        } else {
            res+=((*proot)->left==NULL? 0: (*proot)->left->count)+((*proot)->val==val? 0: 1);
            proot=&((*proot)->right);
        }
    }
    *proot=new Node(val);
    return res;
}

vector<int> countSmaller_solution1(vector<int>& nums) {
    if(nums.size()==0) return {};
    vector<int> res(nums.size(), 0);
    Node* root=new Node(nums.back());
    for(int i=nums.size()-2; i>=0; --i) {
        res[i]=helper_solution1(root, nums[i]);
    }
    return res;
}

void helper_solution2(vector<int>& nums, vector<int>& pos, vector<int>& res, int start, int end) {
    if(start==end) return;
    int mid=start+(end-start)/2;
    helper_solution2(nums, pos, res, start, mid);
    helper_solution2(nums, pos, res, mid+1, end);
    vector<int> tpos;
    for(int pos1=start, pos2=mid+1; pos1<=mid || pos2<=end; ) {
        int up=pos1<=mid? nums[pos[pos1]]: INT_MIN;
        int down=pos2<=end? nums[pos[pos2]]: INT_MIN;
        if(up>down) {
            res[pos[pos1]]+=end-pos2+1;
            tpos.push_back(pos[pos1++]);
        } else {
            tpos.push_back(pos[pos2++]);
        }
    }
    copy(tpos.begin(), tpos.end(), pos.begin()+start);
}

vector<int> countSmaller_solution2(vector<int>& nums) {
    if(nums.size()==0) return {};
    vector<int> res(nums.size(), 0), pos(nums.size(), 0);
    for(int i=0; i<nums.size(); ++i) pos[i]=i;
    helper_solution2(nums, pos, res, 0, nums.size()-1);
    return res;
}

vector<int> countSmaller_solution3(vector<int>& nums) {
    if(nums.size()==0) return {};
    vector<int> res(nums.size(), 0);
    unordered_map<int, int> bit;
    int mini=INT_MAX, maxi=INT_MIN;
    for(auto& v: nums) mini=min(mini, v);
    for(auto& v: nums) {
        v=v-mini+1;
        maxi=max(maxi, v);
    }
    for(int i=nums.size()-1; i>=0; --i) { 
        int count=0;
        for(int u=nums[i]-1; u; u-=(u&(-u))) count+=bit[u];
        res[i]=count;
        for(int u=nums[i]; u<=maxi; u+=(u&(-u))) bit[u]+=1;
    }
    return res;
}

vector<int> countSmaller_solution4(vector<int>& nums) {
    if(nums.size()==0) return {};
    vector<int> sorted_nums=nums, res(nums.size(), 0), bit(nums.size()+1, 0);
    unordered_map<int, int> map;
    sort(sorted_nums.begin(), sorted_nums.end());
    for(int i=0; i<sorted_nums.size(); ++i) map[sorted_nums[i]]=i;
    for(int i=nums.size()-1; i>=0; --i) { 
        int count=0;
        for(int u=map[nums[i]]; u; u-=(u&(-u))) count+=bit[u];
        res[i]=count;
        for(int u=map[nums[i]]+1; u<=nums.size(); u+=(u&(-u))) bit[u]+=1;
    }
    return res;
}

int count_node(vector<int>& st, int st_start, int st_end, int start, int end, int pos) {
    if(start<=st_start && end>=st_end) return st[pos];
    if(start>st_end || end<st_start) return 0;
    int mid=st_start+(st_end-st_start)/2;
    return count_node(st, st_start, mid, start, end, 2*pos+1) + count_node(st, mid+1, st_end, start, end, 2*pos+2);
}

void update_node(vector<int>& st, int start, int end, int val, int pos) {
    ++st[pos];
    if(start==end) return;
    int mid=start+(end-start)/2;
    if(val<=mid) update_node(st, start, mid, val, 2*pos+1);
    else update_node(st, mid+1, end, val, 2*pos+2);
}

vector<int> countSmaller(vector<int>& nums) {
    if(nums.size()==0) return {};
    int len=pow(2, ceil(log2(nums.size())));
    vector<int> sorted_nums=nums, res(nums.size(), 0), st(2*len-1, 0);
    unordered_map<int, int> map;
    sort(sorted_nums.begin(), sorted_nums.end());
    for(int i=0; i<sorted_nums.size(); ++i) map[sorted_nums[i]]=i;
    for(int i=nums.size()-1; i>=0; --i) {
        res[i]=count_node(st, 0, len-1, 0, map[nums[i]]-1, 0);
        update_node(st, 0, len-1, map[nums[i]], 0);
    }
    return res;
}

int main() {
    vector<int> nums={5,2,6,1};
    auto res=countSmaller(nums);
    for(auto& v: res) cout << v << "\t";
    cout << endl;
}
