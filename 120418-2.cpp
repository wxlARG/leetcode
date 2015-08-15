#include<iostream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

void func(vector<vector<int> >& result, vector<int>& tmp, int n, int start, int remain)
{
	if(remain == 0)
	{
		result.push_back(tmp);
		return;
	}

	for(int i=start; i<=n-remain+1; ++i)
	{
		tmp.push_back(i);
		func(result,tmp,n,i+1,remain-1);
		tmp.pop_back();
	}
}

vector<vector<int> > combine(int n, int k)
{
	vector<vector<int> > result;
	vector<int> tmp;
	func(result,tmp,n,1,k);
	return result;
}

int main()
{
	vector<vector<int> > result = combine(4,2);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
