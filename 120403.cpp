#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;

vector<string> fullJustify(vector<string> &words, int L)
{
	int start = 0;
	int end = 0;
	vector<string> results;

	while(end<words.size())
	{
		string result;
		vector<int> spacenum;
		start = end;
		int curlen = 0;
		while((end<words.size()) && (curlen + words[end].size() + 1 <= L+1))
		{
			curlen += words[end].size()+1;
			spacenum.push_back(1);
			++end;
		}

		spacenum.pop_back();
		--curlen;
		if(end-start == 1)
		{
			result.append(words[start]);
			result.append(L-words[start].size(),' ');
		}
		else if(end == words.size())
		{
			for(int i=start; i<end; ++i)
			{
				result.append(words[i]);
				if(i<end-1)
					result.append(1,' ');
			}
			result.append(L-result.size(), ' ');
		}
		else
		{
			int remain = L-curlen;
			int block = remain/spacenum.size();
			remain %= spacenum.size();

			for(int i=start; i<end; ++i)
			{
				result.append(words[i]);
				if(i-start < spacenum.size())
				{
					if(remain > 0)
					{
						result.append(spacenum[i-start]+block+1,' ');
						--remain;
					}
					else
						result.append(spacenum[i-start]+block,' ');
				}
			}
		}

		results.push_back(result);
	}

	return results;
}

int main()
{
	string str[] = {"What","must","be","shall","be."};
	vector<string> words;
	for(int i=0; i<sizeof(str)/sizeof(str[0]); ++i)
		words.push_back(str[i]);

	vector<string> result = fullJustify(words,12);
	for(int i=0; i<result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
