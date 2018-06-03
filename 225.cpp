#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

class Stack {
	public:
		Stack(): head(&q1), cache(&q2) {}

		// Push element x onto stack.
		void push(int x) {
			if(head->size())
			{
				cache->push(head->front());
				head->pop();
			}
			head->push(x);
		}

		// Removes the element on top of the stack.
		void pop() {
			make_head();
			head->pop();
		}

		// Get the top element.
		int top() {
			make_head();
			return head->front();
		}

		// Return whether the stack is empty.
		bool empty() {
			make_head();
			return head->empty();
		}

		void make_head()
		{
			if(!head->empty())
				return;

			while(cache->size() > 1)
			{
				head->push(cache->front());
				cache->pop();
			}

			swap(head, cache);
		}

	private:
		queue<int> *head, *cache;
		queue<int> q1, q2;
};

int main()
{
	Stack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.pop();
	stack.pop();
	stack.pop();
	cout << stack.empty() << endl;

	return 0;
}
