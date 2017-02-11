#include<iostream>
#include<sstream>
#include<vector>
#include<deque>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

void func(vector<string>& result, string& s, int pos, string& cache, vector<char>& stack, int& max)
{
    if(pos==s.size())
    {
        if(stack.empty())
        {
            if(max==-1 || cache.size()==max)
            {
                result.push_back(cache);
                if(max==-1)
                    max = cache.size();
            }
        }
        return;
    }

    if(s[pos]!='(' && s[pos]!=')')
    {
        cache += s[pos];
        func(result,s,pos+1,cache,stack,max);
        cache.pop_back();
        return;
    }

    if(s[pos] == '(')
    {
        stack.push_back('(');
        cache.append("(");
        func(result,s,pos+1,cache,stack,max);
        stack.pop_back();
        cache.pop_back();

        while(s[++pos]=='(');
        func(result,s,pos,cache,stack,max);
    }
    else if(s[pos] == ')')
    {
        if(stack.empty())
            func(result,s,pos+1,cache,stack,max);
        else
        {
            stack.pop_back();
            cache.append(")");
            func(result,s,pos+1,cache,stack,max);
            stack.push_back('(');
            cache.pop_back();

            while(s[++pos]==')');
            func(result,s,pos,cache,stack,max);
        }
    }
}

vector<string> removeInvalidParentheses(string s)
{
    vector<string> result;
    string cache;
    vector<char> stack;
    int max = -1;
    func(result,s,0,cache,stack,max);

    return result;
}

int main()
{
    vector<string> result = removeInvalidParentheses(")(");
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;
	return 0;
}
