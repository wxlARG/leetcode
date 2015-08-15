#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int largestRectangleArea(vector<int> &height)
{
	int result = 0;
	deque<int> stack1;
	deque<int> stack2;

	for(int i=0; i<height.size(); ++i)
	{
		if(stack1.empty() || stack1.back() < height[i])
		{
			stack1.push_back(height[i]);
			stack2.push_back(1);
		}
		else if(stack1.back() == height[i])
		{
			++stack2.back();
		}
		else
		{
			int barlen = 0;
			while(!stack1.empty() && stack1.back() > height[i])
			{
				int tmpheight = stack1.back();
				barlen += stack2.back();
				stack1.pop_back();
				stack2.pop_back();
				result = max(result, barlen*tmpheight);
			}

			if(!stack1.empty() && stack1.back() == height[i])
				stack2.back() += 1+barlen;
			else
			{
				stack1.push_back(height[i]);
				stack2.push_back(barlen+1);
			}
		}
	}

	int barlen = 0;
	while(!stack1.empty())
	{  
		int tmpheight = stack1.back();
		barlen += stack2.back();
		stack1.pop_back();  
		stack2.pop_back();  
		result = max(result, barlen*tmpheight);
	}

	return result;
}

int main()
{
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		height.push_back(arr[i]);

	int result = largestRectangleArea(height);
	cout << result << endl;
	return 0;
}
