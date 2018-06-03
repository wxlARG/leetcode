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

int maxArea(vector<int> &height)
{
	int Amax = INT_MIN;
	int size = height.size();
	int start = 0;
	int end = size-1;

	while(start < end)
	{
		int tmpMax = min(height[start],height[end]) * (end-start);
		Amax = max(Amax,tmpMax);
		if(height[start] < height[end])
			++start;
		else
			--end;
	}

	return Amax;
}

int main()
{
	vector<int> height;
	height.push_back(1);
	height.push_back(2);
	height.push_back(3);
	height.push_back(1);
	int result = maxArea(height);
	cout<<result<<endl;
	return 0;
}


