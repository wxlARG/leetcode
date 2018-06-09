#include"common.h"
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty()) load();
        int res=out.top();
        out.pop();
        return res;
        
    }
    
    /** Get the front element. */
    int peek() {
        if(out.empty()) load();
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
private:
    void load() {
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
    stack<int> in, out;
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);  
    cout << queue.peek() << endl;
    cout << queue.pop() << endl;
    cout << queue.empty() << endl;
}
