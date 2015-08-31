#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

void func(vector<int> &candidates, vector<vector<int> >& result, vector<int>& tmp, int start, int end, int target)
{
	if(target == 0)
	{
		result.push_back(tmp);
		return;
	}

	if(start > end || target < candidates[start])
		return;

	for(int i=0; i<=target/candidates[start]; ++i)
	{
		int val = candidates[start] * i;
		for(int j=0; j<i; ++j)
			tmp.push_back(candidates[start]);

		func(candidates, result, tmp, start+1, end, target-val);

		for(int j=0; j<i; ++j)
			tmp.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int> > result;
	vector<int> tmp;

	func(candidates, result, tmp, 0, candidates.size()-1, target);
	return result;
}

int main()
{
	int arr[] = {8,7,4,3};
	vector<int> candidates;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		candidates.push_back(arr[i]);

	vector<vector<int> > result = combinationSum(candidates, 11);

	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
