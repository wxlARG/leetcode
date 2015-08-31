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

int threeSumClosest(vector<int> &num, int target)
{
	int result;
	int dis = INT_MAX;
	stable_sort(num.begin(),num.end());
	for(int i=0; i<num.size(); ++i)
	{
		if(i > 0 && num[i] == num[i-1])
			continue;

		int start = i+1;
		int end = num.size()-1;
		
		while(start < end)
		{
			int tmpsum = num[i] + num[start] + num[end];
			if(tmpsum == target)
			{
				return target;
			}
			else if(tmpsum < target)
			{
				if(target - tmpsum < dis)
				{
					dis = target - tmpsum;
					result = tmpsum;
				}

				++start;
				while(start < end && num[start] == num[start-1])
					++start;
			}
			else
			{
				if(tmpsum - target < dis)
				{
					dis = tmpsum - target;
					result = tmpsum;
				}

				--end;
				while(start < end && num[end] == num[end+1])
					--end;
			}
		}
	}

	return result;
}

int main()
{
	int arr[] = {-1,2,1,-4};
	int target = 1;
	vector<int> num;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	int result = threeSumClosest(num,target);
	cout << result << endl;
	return 0;
}
