#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

int minDistance(string word1, string word2)
{
	int last = 0;
	vector<int> cache(word1.size()+1,0);
	for(int i=0; i<cache.size(); ++i)
		cache[i] = i;

	for(int j=0; j<word2.size(); ++j)
	{
		for(int i=0; i<word1.size()+1; ++i)
		{
			int tmp = cache[i];
			if(i==0)
				++cache[i];
			else
			{
				if(word2[j] == word1[i-1])
					cache[i] = last;
				else
				{
					int tmpmin = min(last+1,cache[i-1]+1);
					cache[i] = min(tmpmin, cache[i]+1);
				}
			}

			last = tmp;
		}
	}
	return cache[cache.size()-1];
}

int main()
{
	string word1 = "ab";
	string word2 = "a";

	int result = minDistance(word1,word2);
	cout << result << endl;
	return 0;
}
