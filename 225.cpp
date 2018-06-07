#include"common.h"
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        t=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        for(int i=0; i<q.size()-1; ++i) {
            q.push(q.front());
            t=q.front();
            q.pop();
        }
        int ret=q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return t;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
    int t;
};

int main() {
    MyStack obj;
    obj.push(1);
    obj.push(2);
    cout << obj.top() << endl;
    cout << obj.pop() << endl;
    cout << obj.empty() << endl;
}
