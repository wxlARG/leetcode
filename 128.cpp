#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include"common.h"
using namespace std;

int longestConsecutive_solution1(vector<int>& nums) {
    int res=0;
    unordered_set<int> cache;
    unordered_set<int> done;
    for(auto &v: nums) cache.insert(v);
    for(auto &v: nums) {
        int len=1;
        for(int p=v-1; cache.find(p)!=cache.end() && done.find(p)==done.end(); --p, ++len) done.insert(p);
        for(int n=v+1; cache.find(n)!=cache.end() && done.find(n)==done.end(); ++n, ++len) done.insert(n);
        res=max(res, len);
    }
    return res;
}

int longestConsecutive(vector<int>& nums) {
    int res=0;
    unordered_set<int> cache;
    for(auto &v: nums) cache.insert(v);
    for(auto &v: nums) {
        int len=1;
        for(int p=v-1; cache.find(p)!=cache.end(); --p, ++len) cache.erase(p);
        for(int n=v+1; cache.find(n)!=cache.end(); ++n, ++len) cache.erase(n);
        res=max(res, len);
    }
    return res;
}

int main() {
    vector<int> nums={100, 4, 200, 1, 3, 2, 5};
    //vector<int> nums={1, 2, 2, 3, 4};
    cout << longestConsecutive(nums) << endl;
}
