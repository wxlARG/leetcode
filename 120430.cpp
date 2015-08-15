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

bool func(string& s1, int start1, int end1, string& s2, int start2, int end2)
{
	if(start1 > end1 || start2 > end2)
		return false;
	if(end1-start1 != end2-start2)
		return false;

	bool equalflag = 1;
	for(int i=0; i<=end1-start1; ++i)
	{
		if(s1[start1+i]!=s2[start2+i])
		{
			equalflag = 0;
			break;
		}
	}

	if(equalflag == 1)
		return true;

	string str1,str2,str3;
	for(int i=0; i<end1-start1; ++i)
	{
		str1 += s1[start1+i];
		sort(str1.begin(),str1.end());

		str2 += s2[start2+i];
		sort(str2.begin(),str2.end());

		str3 += s2[end2-i];
		sort(str3.begin(),str3.end());

		if(str1 == str2)
			if(func(s1,start1,start1+i,s2,start2,start2+i) && func(s1,start1+i+1,end1,s2,start2+i+1,end2))
				return true;

		if(str1 == str3)
			if(func(s1,start1,start1+i,s2,end2-i,end2) && func(s1,start1+i+1,end1,s2,start2,end2-i-1))
				return true;
	}

	return false;
}

/*bool isScramble(string s1, string s2)
{
	return func(s1,0,s1.size()-1,s2,0,s2.size()-1);
}*/

bool isScramble(string s1, string s2)
{
	if(s1.size() != s2.size())
		return false;

	vector<vector<vector<bool> > > cache(s1.size());
	for(int i=0; i<s1.size(); ++i)
	{
		vector<vector<bool> > tmp1(s1.size());
		for(int j=0; j<s1.size(); ++j)
		{
			vector<bool> tmp2(s1.size());
			tmp1[j] = tmp2;
		}
		cache[i] = tmp1;
	}

	for(int i=0; i<s1.size(); ++i)
		for(int j=0; j<s1.size(); ++j)
			if(s1[i] == s2[j])
				cache[0][i][j] = 1;

/*	for(int i=0; i<s1.size(); ++i)
	{
		for(int j=0; j<s1.size(); ++j)
			cout << cache[0][i][j] << "\t";
		cout << endl;
	}*/

	for(int l=1; l<s1.size(); ++l)
	{
		for(int i=0; i<s1.size()-l; ++i)
		{
			for(int j=0; j<s1.size()-l; ++j)
			{
				cache[l][i][j] = 0;
				for(int k=0; k<l; ++k)
				{
					if((cache[k][i][j] && cache[l-k-1][i+k+1][j+k+1]) || (cache[k][i][j+l-k] && cache[l-k-1][i+k+1][j]))
					{
						cache[l][i][j] = 1;
						break;
					}
				}
			}
		}
	}
	return cache[s1.size()-1][0][0];
}

int main()
{
	string s1 = "aa";
	string s2 = "ab";
	bool result = isScramble(s1,s2);
	cout << result << endl;
	return 0;
}
