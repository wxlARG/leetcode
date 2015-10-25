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
#include<unordered_map>
using namespace std;

bool wordPattern(string pattern, string str)
{
    int ppos=0, spos=0;
    unordered_map<char, string> cache;
    unordered_map<string, char> rcache;
    string tmp;

    while(spos<str.size())
    {
        if(str[spos]==' ')
        {
            if(cache.find(pattern[ppos]) != cache.end())
                if(ppos>=pattern.size() || cache[pattern[ppos]] != tmp)
                    return 0;

            if(rcache.find(tmp) != rcache.end())
                if(ppos>=pattern.size() || rcache[tmp] != pattern[ppos])
                    return 0;

            cache.insert(make_pair(pattern[ppos],tmp));
            rcache.insert(make_pair(tmp,pattern[ppos]));
            ++ppos;
            tmp.clear();
        }
        else
            tmp += str[spos];
        ++spos;
    }

    if(!tmp.empty())
    {
        if(cache.find(pattern[ppos]) != cache.end())
            if(ppos>=pattern.size() || cache[pattern[ppos]] != tmp)
                return 0;

        if(rcache.find(tmp) != rcache.end())
            if(ppos>=pattern.size() || rcache[tmp] != pattern[ppos])
                return 0;

        cache.insert(make_pair(pattern[ppos],tmp));
        rcache.insert(make_pair(tmp,pattern[ppos]));
        ++ppos;
        tmp.clear();
    }

    if(ppos != pattern.size())
        return 0;

    return 1;
}

int main()
{
    bool result = wordPattern("abba","dog cat cat dog");
    cout << result << endl;
	return 0;
}
