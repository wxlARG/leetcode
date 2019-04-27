#include"common.h"
using namespace std;

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand(time(0));
        head_=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res=0;
        int count=0;
        for(ListNode* p=head_; p; p=p->next) {
            ++count;
            if(rand()%count==0) res=p->val;
        }
        return res;
    }
private:
    ListNode* head_;
};

int main() {
	Solution solution(create_list({1, 2, 3}));
    cout << solution.getRandom() << endl;
}
