#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

void func(vector<vector<int> >& result, vector<int> &num, int start)
{
	if(start == num.size())
	{
		result.push_back(num);
		return;
	}

	set<int> history;
	
	for(int i=start; i<num.size(); ++i)
	{
		if(history.find(num[i]) != history.end())
			continue;

		history.insert(num[i]);
		swap(num[start],num[i]);
		func(result,num,start+1);
		swap(num[start],num[i]);
	}
}

vector<vector<int> > permute(vector<int> &num)
{
	vector<vector<int> > result;
	if(num.size() == 0)
		return result;

	func(result,num,0);
	return result;
}

int main()
{
	vector<int> num;
	int arr[] = {1,2,2,1};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		num.push_back(arr[i]);

	vector<vector<int> > result = permute(num);

	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
