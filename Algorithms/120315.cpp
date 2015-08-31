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

/*bool isMatch(const char *s, const char *p)
{
	int slen = strlen(s);
	int plen = strlen(p);
	bool* a = new bool [slen+1];
	a[0] = 1;

	for(int i=0; i<plen; ++i)
	{
		if(p[i] == '*')
		{
			int max = a[0];
			for(int j=1; j<slen+1; ++j)
			{
				if(a[j] > max)
					max = a[j];
				a[j] = max;
			}
			continue;
		}

		for(int j=slen-1; j>=0; --j)
		{
			if(p[i] == '?' || p[i] == s[j])
				a[j+1] = a[j];
			else
				a[j+1] = 0;
		}

		a[0] = 0;
	}

	return a[slen];
}*/

bool func(const char *s, int sstart, int slen, const char *p, int pstart, int plen, int& matchFlag)
{
	if(pstart == plen && sstart == slen)
		return true;

	if(sstart > slen || pstart == plen)
		return false;

	if(matchFlag == 0)
		return false;

	if(p[pstart] == '?')
		return func(s,sstart+1,slen,p,pstart+1,plen,matchFlag);

	if(p[pstart] != '*')
	{
		while(sstart<slen && pstart<plen && s[sstart] == p[pstart])
		{
			++sstart;
			++pstart;
		}

		if(pstart == plen && sstart == slen)
			return true;

		if(sstart > slen)
			return false;

		if(p[pstart] == '?' || p[pstart] == '*')
			return func(s,sstart,slen,p,pstart,plen,matchFlag);
		else
			return false;
	}

	if(p[pstart] == '*')
	{
		while(p[pstart] == '*' || p[pstart] == '?')
		{
			if(p[pstart] == '?')
				++sstart;
			++pstart;
		}

		if(sstart > slen)
			return false;

		if(pstart == plen)
			return true;

		int pend = pstart;
		while(pend<plen && p[pend]!='*' && p[pend]!='?')
			++pend;

		vector<int> next(pend-pstart,0);
		next[0] = -1;

		int j=0;
		int k=-1;

		while(j<(pend-pstart-1))
		{
			if(k==-1 || p[pstart+j] == p[pstart+k])
			{
				++j;
				++k;
				next[j] = k;
			}
			else
				k = next[k];
		}

		int i=sstart;
		j=0;
		while(i<slen && j<(pend-pstart))
		{
			if(j==-1 || s[i] == p[pstart+j])
			{
				++i;
				++j;
			}
			else
				j=next[j];

			if(j==(pend-pstart))
			{
//				cout << i <<"\t"<< pstart<<"\t" << pstart+j<<"\t" <<pend << endl;
//				string tmp(p,pstart,j);
//				cout << tmp << endl;
				if(func(s,i,slen,p,pstart+j,plen,matchFlag))
					return true;

				if(matchFlag == 0)
					return false;

				--i;
				--j;
				j=next[j];
			}
		}
		matchFlag = 0;
		return false;
	}
}

bool isMatch(const char *s, const char *p)
{
	int matchFlag=1;
	return func(s,0,strlen(s),p,0,strlen(p),matchFlag);
}

int main()
{
//	bool result = isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");
	bool result = isMatch("mississippi", "m*issip*");

	//**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb
	cout << result << endl;
	return 0;
}
