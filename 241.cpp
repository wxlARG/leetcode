#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

vector<int> func(vector<string> &cache, int start, int end)
{
    vector<int> result;

    if(start == end)
        result.push_back(atoi(cache[start].c_str()));

    for(int pos=start+1; pos<=end; pos+=2)
    {
        vector<int> left = func(cache, start, pos-1);
        vector<int> right = func(cache, pos+1, end);

        for(int i=0; i<left.size(); ++i)
        {
            for(int j=0; j<right.size(); ++j)
            {
                if(cache[pos][0]=='+')
                    result.push_back(left[i]+right[j]);
                else if(cache[pos][0]=='-')
                    result.push_back(left[i]-right[j]);
                else
                    result.push_back(left[i]*right[j]);
            }
        }
    }

    return result;
}

vector<int> diffWaysToCompute(string input)
{
    vector<string> cache;
    int start=0;
    
    for(int pos=0; pos<input.size(); ++pos)
    {
        if(input[pos]=='+' || input[pos]=='-' || input[pos]=='*')
        {
            cache.push_back(string(input,start,pos-start));
            cache.push_back(string(input,pos,1));
            start = pos+1;
        }
    }

    cache.push_back(string(input,start,input.size()-start));

    return func(cache,0,cache.size()-1);
}

int main()
{
	vector<int> result = diffWaysToCompute("11");

    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;
	return 0;
}
