#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<sstream>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> result;

	if(nums.size() == 0)
		return result;

	string tmp, numstr, lastnumstr;
	int last = nums[0];

	stringstream stream;
	stream << last;
	stream >> numstr;
	lastnumstr = numstr;
	tmp = numstr;

	for(int i=1; i<nums.size(); ++i)
	{
		stream.clear();
		stream << nums[i];
		stream >> numstr;

		if(nums[i]-last==1)
		{
			if(tmp.back()!='>')
				tmp += "->";
		}
		else
		{
			if(tmp.back()=='>')
				tmp += lastnumstr;

			result.push_back(tmp);
			tmp.clear();

			tmp = numstr;
		}

		last = nums[i];
		lastnumstr = numstr;
	}

	if(tmp.back()=='>')
		tmp += lastnumstr;
	result.push_back(tmp);

	return result;
}

int main()
{
	int arr[] = {0,1,2,4,5,7,11};
	vector<int> nums;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		nums.push_back(arr[i]);

	vector<string> result = summaryRanges(nums);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
