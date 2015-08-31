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

bool isIsomorphic(string s, string t)
{
	vector<vector<char> > cache(255,vector<char>(2,0));

	for(int i=0; i<s.size(); ++i)
	{
		if(cache[s[i]][0] == 0 && cache[t[i]][1] == 0)
		{
			cache[s[i]][0] = t[i];
			cache[t[i]][1] = s[i];
		}
		else if(cache[s[i]][0] == t[i] && cache[t[i]][1] == s[i])
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
	bool result = isIsomorphic("ab","aa");
	cout << result << endl;
	return 0;
}
