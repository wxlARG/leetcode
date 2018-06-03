#include"common.h"
using namespace std;

class MinStack {
    private:
        stack<int> normal_stack;
        stack<pair<int, int>> min_stack;
    public:
        MinStack() {
        }

        void push(int x) {
            normal_stack.push(x);
            if(min_stack.empty()) min_stack.push({x, 1});
            else if(x<min_stack.top().first) min_stack.push({x, 1});
            else if(x==min_stack.top().first) ++min_stack.top().second;
        }

        void pop() {
            if(normal_stack.size()==0) return;
            int val=normal_stack.top();
            normal_stack.pop();
            if(val==min_stack.top().first) --min_stack.top().second;
            if(min_stack.top().second==0) min_stack.pop();
        }

        int top() {
            return normal_stack.top();
        }

        int getMin() {
            return min_stack.top().first;
        }
};

int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin() << endl;
}
