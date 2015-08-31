#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int climbStairs(int n)
{
	if(n==1)
		return 1;

	deque<int> queue;
	queue.push_back(1);
	queue.push_back(2);

	for(int i=3; i<=n; ++i)
	{
		int tmp = queue.front();
		queue.pop_front();
		queue.push_back(tmp+queue.front());
	}

	return queue[1];
}

int main()
{
	int result = climbStairs(5);
	cout << result << endl;
	return 0;
}
