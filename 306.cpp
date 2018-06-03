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

string funcadd(string &s1, string &s2)
{
    if(s1.size() > s2.size())
        return funcadd(s2,s1);

    string result;
    int flag = 0;
    int pos1 = s1.size()-1, pos2 = s2.size()-1;
    for(;pos1>=0 && pos2>=0; --pos1,--pos2)
    {
        int val = s1[pos1]-'0'+s2[pos2]-'0'+flag;
        flag = val/10;
        result += '0'+val%10;
    }

    for(;pos2>=0;--pos2)
    {
        int val = s2[pos2]-'0'+flag;
        flag = val/10;
        result += '0'+val%10;
    }

    for(;flag!=0;flag/=10)
    {
        result += '0'+flag%10;
    }

    reverse(result.begin(),result.end());
    return result;
}

bool func(string &num, int pos, string &s1, string &s2)
{
    if(pos == num.size())
        return 1;

    string tmp = funcadd(s1, s2);
    if(tmp.size()>num.size()-pos)
        return 0;

    string tmp2 = string(num,pos,tmp.size());
    if(tmp != tmp2)
        return 0;
    return func(num, pos+tmp2.size(), s2, tmp2);
}

bool isAdditiveNumber(string num)
{
    for(int len1=1; len1<=num.size()/2; ++len1)
    {
        string tmp1(num,0,len1);
        for(int len2=1; len2<num.size()-len1; ++len2)
        {
            string tmp2(num,len1,len2);
            if(num[len1]=='0' && len2>1)
                continue;
            if(func(num,len1+len2,tmp1,tmp2))
                return 1;
        }
    }
    return 0;
}

int main()
{
    bool result = isAdditiveNumber("101");
    cout << result << endl;
    return 0;
}
