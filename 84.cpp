#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include"common.h"
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int res=0;
    heights.push_back(INT_MIN);
    vector<pair<int, int>> c;
    for(int i=0; i<heights.size(); ++i) {
        while(!c.empty() && c.back().first>=heights[i]) {
            int height=c.back().first, length=-1;
            c.pop_back();
            if(!c.empty()) length = c.back().second;
            res = max(res, height * (i-length-1));
        }
        c.push_back({heights[i], i});
    }
    return res;
}

int main() {
    //vector<int> heights={2,1,5,6,2,3};
    vector<int> heights={5, 4, 1, 2};
    //vector<int> heights={2, 1, 2};
    cout << largestRectangleArea(heights) << endl;
}
