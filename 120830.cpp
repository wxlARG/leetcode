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

bool isInterleave(string s1, string s2, string s3)
{
	if(s3.size() != s1.size()+s2.size())
		return 0;

	vector<vector<bool> > dp(s1.size()+1);
	for(int i=0; i<=s1.size(); ++i)
	{
		vector<bool> tmp(s2.size()+1,0);
		dp[i] = tmp;
	}
	dp[0][0] = 1;

	for(int i=0; i<dp.size(); ++i)
	{
		for(int j=0; j<dp[i].size(); ++j)
		{
			if(i>0 && dp[i-1][j]==1 && s1[i-1]==s3[i+j-1])
				dp[i][j]=1;
			else if(j>0 && dp[i][j-1]==1 && s2[j-1]==s3[i+j-1])
				dp[i][j]=1;
		}
	}
	return dp[s1.size()][s2.size()];
}

int main()
{
	string s1("aabcc");
	string s2("dbbca");
	string s3("aadbbbaccc");

	bool result = isInterleave(s1,s2,s3);
	cout << result << endl;
	return 0;
}
