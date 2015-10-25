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

void func(string &num, int pos, vector<string> &result, long long muti, long long merge, string &str, int target, long long total)
{
    if(pos == num.size())
    {
//        cout << total << endl;
        total += muti*merge;
//        cout << "sssss" << endl;
//        cout << str << endl;
//        cout << muti<< "\t"<<merge << "\t"<<total << endl;
//        cout << endl;
        if(total==target)
            result.push_back(str);
        return;
    }

    for(int i=0; i<4; ++i)
    {
        if(i==0 && merge==0) 
            continue;

        int tmp = num[pos]-'0';
        long long tmp_merge=merge,tmp_muti=muti,tmp_total=total;
        if(i==0)
        {
            if(merge>=0)
                tmp_merge = merge*10+tmp;
            else
                tmp_merge = merge*10-tmp;
        }
        else if(i==1)
        {
            tmp_total = total+muti*merge;
            tmp_muti = 1;
            tmp_merge = tmp;
            str.push_back('+');
        }
        else if(i==2)
        {
            tmp_total = total+muti*merge;
            tmp_muti = 1;
            tmp_merge = tmp*-1;
            str.push_back('-');
        }
        else if(i==3)
        {
            tmp_muti *= merge;
            tmp_merge = tmp;
            str.push_back('*');
        }

        str.push_back(num[pos]);
        func(num,pos+1,result,tmp_muti,tmp_merge,str,target,tmp_total);
        if(i!=0)
            str.pop_back();
        str.pop_back();
    }
}

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    if(num.empty())
        return result;

    string str;
    str.push_back(num[0]);
    long long total = 0;
    long long muti = 1;
    long long merge = num[0]-'0';
    func(num,1,result,muti,merge,str,target,total);
    return result;
}

int main()
{
//    vector<string> result = addOperators("2147483647",2147483647);
    vector<string> result = addOperators("2147483648",-2147483648);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;
    return 0;
}
