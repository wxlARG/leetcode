#include<iostream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void func(vector<list<int>> &pos,  vector<pair<int,int>> &cache)
{
    int min = INT_MAX;
    for(int i=0; i<pos.size(); ++i)
    {
        if(pos[i].size()!=0)
        {
            cache[i].first = min;
            min = pos[i].front() < min ? pos[i].front() : min;
        }
    }

    min = INT_MAX;
    for(int i=pos.size()-1; i>=0; --i)
    {
        if(pos[i].size()!=0)
        {
            cache[i].second = min;
            min = pos[i].back() < min ? pos[i].back() : min;
        }
    }
}

string removeDuplicateLetters(string s)
{
    string result;
    vector<list<int>> pos(26);
    vector<pair<int,int>> cache(26);
    for(int i=0; i<s.size(); ++i)
        pos[s[i]-'a'].push_back(i);

    func(pos,cache);
    for(int i=0; i<s.size(); ++i)
    {
        if(pos[s[i]-'a'].size() == 0)
            continue;

        if(pos[s[i]-'a'].size() == 1 || cache[s[i]-'a'].first>cache[s[i]-'a'].second)
        {
            result.push_back(s[i]);
            pos[s[i]-'a'].clear();
        }
        else
            pos[s[i]-'a'].pop_front();
        func(pos,cache);
    }
    return result;
}

int main()
{
    string result = removeDuplicateLetters("cbacdcbc");
    cout << result << endl;
    return 0;
}
