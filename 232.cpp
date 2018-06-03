#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        move();
		stack2.pop();
    }

    // Get the front element.
    int peek(void) {
        move();
		return stack2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		move();
		return stack2.empty();
    }

private:
	stack<int> stack1, stack2;

	void move() {
		if(stack2.empty())
		{
			while(!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
	}
};

int main()
{
	Queue queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);

	cout << queue.peek() << endl;
	queue.pop();
	cout << queue.peek() << endl;
	queue.pop();
	cout << queue.peek() << endl;
	queue.pop();
	cout << queue.empty() << endl;

	return 0;
}
