#include"common.h"
using namespace std;

bool isRectangleCover_solution1(vector<vector<int>>& rectangles) {
    sort(rectangles.begin(), rectangles.end(), less<vector<int>>());
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i=0; i<rectangles.size() && rectangles[i][0]==rectangles[0][0]; ++i) pq.push({rectangles[i][0], rectangles[i][1], rectangles[i][3]});
    int pos=0;
    while(!pq.empty()) {
        int lower=pq.top()[1], x=pq.top()[0], upper;
        do {
            upper=pq.top()[2];
            pq.pop();
        } while(!pq.empty() && pq.top()[0]==x && pq.top()[1]==upper);
        if(!pq.empty() && pq.top()[0]==x && pq.top()[1]<upper) return false;
        if(pos==rectangles.size()) break;
        if(rectangles[pos][0]!=x) return false;
        int rlower=rectangles[pos][1], rupper;
        do {
            rupper=rectangles[pos][3];
            pq.push({rectangles[pos][2], rectangles[pos][1], rectangles[pos][3]});
            ++pos;
        } while(pos<rectangles.size() && rectangles[pos][0]==x && rectangles[pos][1]==rupper);
        if(lower!=rlower || upper!=rupper) return false;
    }
    return pos==rectangles.size() && pq.empty();
}

void helper(string pos, unordered_set<string>& cache) {
    if(cache.count(pos)) cache.erase(pos);
    else cache.insert(pos);
}

bool isRectangleCover(vector<vector<int>>& rectangles) {
    int left=INT_MAX, right=INT_MIN, up=INT_MIN, down=INT_MAX;
    unordered_set<string> cache;
    int accu_area=0;
    for(auto& rec: rectangles) {
        accu_area+=(rec[2]-rec[0])*(rec[3]-rec[1]);
        left=min(rec[0], left);
        right=max(rec[2], right);
        up=max(rec[3], up);
        down=min(rec[1], down);
        helper(to_string(rec[0])+"_"+to_string(rec[1]), cache);
        helper(to_string(rec[0])+"_"+to_string(rec[3]), cache);
        helper(to_string(rec[2])+"_"+to_string(rec[1]), cache);
        helper(to_string(rec[2])+"_"+to_string(rec[3]), cache);
    }
    if(accu_area != (right-left)*(up-down)) return false;
    helper(to_string(left)+"_"+to_string(down), cache);
    helper(to_string(left)+"_"+to_string(up), cache);
    helper(to_string(right)+"_"+to_string(down), cache);
    helper(to_string(right)+"_"+to_string(up), cache);
    return cache.empty();
}

int main() {
	vector<vector<int>> rectangles = {
		{1,1,3,3},
		{3,1,4,2},
		{3,2,4,4},
		{1,3,2,4},
		{2,3,3,4}
	};
	cout << isRectangleCover(rectangles) << endl;
}
