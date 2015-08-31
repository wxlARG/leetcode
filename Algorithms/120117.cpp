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

vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > result;
	stable_sort(num.begin(),num.end());
	for(int i=0; i<num.size(); ++i)
	{
		if(i > 0 && num[i] == num[i-1])
			continue;

		int target = 0-num[i];
		int start = i+1;
		int end = num.size()-1;
		
		while(start < end)
		{
			vector<int> tmp;
			if(num[start] + num[end] == target)
			{
				tmp.push_back(num[i]);
				tmp.push_back(num[start]);
				tmp.push_back(num[end]);
				result.push_back(tmp);

				++start;
				while(start < end && num[start] == num[start-1])
					++start;

				--end;
				while(start < end && num[end] == num[end+1])
					--end;
			}
			else if(num[start] + num[end] < target)
			{
				++start;
				while(start < end && num[start] == num[start-1])
					++start;
			}
			else
			{
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
	int arr[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	vector<int> num;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	vector<vector<int> > result = threeSum(num);

	for(int i=0; i<result.size(); ++i)
		cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << "\n";
	return 0;
}
