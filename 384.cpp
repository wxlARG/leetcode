#include"common.h"
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        srand(time(0));
        this->nums=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
       vector<int> res=nums;
       for(int i=0; i<res.size(); ++i) {
           int pos=rand()%(res.size()-i);
           swap(res[i], res[i+pos]);
       }
       return res;
    }
private:
    vector<int> nums;
};

int main() {
	Solution solution({1, 2, 3});
    auto nums=solution.shuffle();
    for(auto num: nums) cout << num << "\t";
    cout << endl;
    nums=solution.reset();
    for(auto num: nums) cout << num << "\t";
    cout << endl;
    nums=solution.shuffle();
    for(auto num: nums) cout << num << "\t";
    cout << endl;
}
