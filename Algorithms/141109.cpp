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

class MinStack {
	public:
		void push(int x) {
			numstack.push(x);
			if(minstack.size()==0 || x<=minstack.top())
				minstack.push(x);
		}

		void pop() {
			int last = numstack.top();
			numstack.pop();
			if(last==minstack.top())
				minstack.pop();
		}

		int top() {
			return numstack.top();
		}

		int getMin() {
			return minstack.top();
		}
	private:
		stack<int> numstack;
		stack<int> minstack;
};

int main()
{
	MinStack test;
	test.push(2);
	test.push(3);
	test.push(1);
	cout << test.top() << endl;
	cout << test.getMin() << endl;
	test.pop();
	cout << test.top() << endl;
	cout << test.getMin() << endl;

	return 0;
}
