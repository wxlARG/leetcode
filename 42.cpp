#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int trap(vector<int>& height) {
    int res=0;
    int start=0, end=height.size()-1;
    while(start<end) {
        int t = min(height[start], height[end]);
        if(height[start]<=height[end]) {
            int pos = start;
            while(height[++pos]<=height[start] && pos<end) {
                res += t-height[pos];
            }
            start = pos;
        } else {
            int pos = end;
            while(height[--pos]<=height[end] && start<pos) {
                res += t-height[pos];
            }
            end = pos;
        }
    }
    return res;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
}
