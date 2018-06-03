#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int maxArea(vector<int>& height) {
    int res = 0;
    for(int i=0, j=height.size()-1; i<j;) {
        res = max(res, (j-i)*min(height[i], height[j]));
        if(height[i]>height[j]) --j;
        else ++i;
    }
    return res;
}

int main() {
    vector<int> height = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << maxArea(height) << endl;
}
