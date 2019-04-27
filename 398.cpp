#include"common.h"
using namespace std;

class Solution {
    public:
        Solution(vector<int> nums): nums_(nums) {
            srand(time(0));
        }

        int pick(int target) {
            int count=0, res=-1;
            for(int i=0; i<nums_.size(); ++i) {
                if(nums_[i]!=target) continue;
                ++count;
                if(rand()%count<1) res=i;
            }
            return res;
        }
    private:
        vector<int> nums_;
};

int main() {
    vector<int> nums={1,2,3,3,3};
    Solution obj(nums);
    cout << obj.pick(3) << endl;
}
