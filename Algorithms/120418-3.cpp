#include<iostream>
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

void func(vector<int> &S, vector<vector<int> >& result, vector<int>& tmp, int start)
{
	if(start == S.size())
	{
		result.push_back(tmp);
		return;
	}

	tmp.push_back(S[start]);
	func(S,result,tmp,start+1);
	tmp.pop_back();

	func(S,result,tmp,start+1);
}

vector<vector<int> > subsets(vector<int> &S)
{
	sort(S.begin(),S.end());
	vector<int> tmp;
	vector<vector<int> > result;

	func(S,result,tmp,0);
	return result;
}

int main()
{
	int arr[] = {4,1,0};
	vector<int> S;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		S.push_back(arr[i]);

	vector<vector<int> > result = subsets(S);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
