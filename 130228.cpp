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

int minCut(string s)
{
	if(s.empty())
		return 0;

	vector<vector<bool> > cache(s.size(), vector<bool>(s.size(),0));
	for(int i=0; i<s.size(); ++i)
		for(int j=0; j<s.size()-i; ++j)
			if(i==0)
				cache[j][j+i] = 1;
			else if(i==1 && s[j]==s[j+i])
				cache[j][j+i] = 1;
			else if(s[j]==s[j+i])
				cache[j][j+i] = cache[j+1][j+i-1];

	vector<int> dp(s.size(),0);
	for(int i=1; i<s.size(); ++i)
	{
		int min = INT_MAX;
		for(int j=0; j<=i; ++j)
		{
			if(j>0 && dp[j-1]>=min)
				continue;

			int tmp = INT_MAX;
			if(!cache[j][i])
				continue;

			if(j==0)
				tmp=0;
			else
				tmp = dp[j-1]+1;

			if(min>tmp)
				min = tmp;
		}
		dp[i] = min;
	}

	return dp[s.size()-1];
}

int main()
{
	int result = minCut("aab");
	cout << result << endl;
	return 0;
}
