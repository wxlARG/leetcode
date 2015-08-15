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

void func(vector<int> &num, vector<vector<int> >& result, vector<int>& tmp, int start, int end, int target)
{
	if(target == 0)
	{
		result.push_back(tmp);
		return;
	}

	if(start > end || target < num[start])
		return;

	int fin = start + 1;
	while(fin<=end && num[fin] == num[start])
		++fin;

	int samenum = fin-start;

	for(int i=0; i<=samenum; ++i)
	{
		int val = num[start]*i;

		for(int j=0; j<i; ++j)
			tmp.push_back(num[start]);

		func(num, result, tmp, fin, end, target-val);

		for(int j=0; j<i; ++j)
			tmp.pop_back();
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target)
{
	sort(num.begin(), num.end());
	vector<vector<int> > result;
	vector<int> tmp;

	func(num, result, tmp, 0, num.size()-1, target);
	return result;
}

int main()
{
	int arr[] = {10,1,2,7,6,1,5};
	vector<int> num;

	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	vector<vector<int> > result = combinationSum2(num, 8);

	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
