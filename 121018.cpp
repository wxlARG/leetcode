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

int numDistinct(string S, string T)
{
	if(S.size() < T.size())
		return 0;

	vector<int> dp(S.size()+1,1);
	int last;

	for(int i=0; i<T.size(); ++i)
	{
		for(int j=i; j<=S.size(); ++j)
		{
			int tmp = dp[j];
			if(j==i)
				dp[j]=0;
			else if(S[j-1] == T[i])
				dp[j] = dp[j-1]+last;
			else
				dp[j] = dp[j-1];
			last = tmp;
		}
	}

	return dp[S.size()];
}

int main()
{
	string S("rabbbit");
	string T("rabbit");
	int result = numDistinct(S,T);
	cout << result << endl;
	return 0;
}
