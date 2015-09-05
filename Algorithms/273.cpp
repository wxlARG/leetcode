#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<map>
#include<stdlib.h>
using namespace std;

string func(map<int, string> &cache, int num)
{
    string result;
    if(num/100 != 0)
        result = cache[num/100] + cache[100];
    num %= 100;

    if(num == 0)
        return result;

    if(cache.find(num) != cache.end())
        result += cache[num];
    else
        result += cache[num/10*10] + cache[num%10];
    return result;
}

string numberToWords(int num)
{
    string result;
    map<int, string> cache;
    cache[0] = "Zero "; cache[1] = "One "; cache[2] = "Two "; 
    cache[3] = "Three "; cache[4] = "Four "; cache[5] = "Five "; 
    cache[6] = "Six "; cache[7] = "Seven "; cache[8] = "Eight ";
    cache[9] = "Nine "; cache[10] = "Ten "; cache[11] = "Eleven "; 
    cache[12] = "Twelve "; cache[13] = "Thirteen "; cache[14] = "Fourteen "; 
    cache[15] = "Fifteen "; cache[16] = "Sixteen "; cache[17] = "Seventeen "; 
    cache[18] = "Eighteen "; cache[19] = "Nineteen "; cache[20] = "Twenty "; 
    cache[30] = "Thirty "; cache[40] = "Forty "; cache[50] = "Fifty "; 
    cache[60] = "Sixty "; cache[70] = "Seventy "; cache[80] = "Eighty "; 
    cache[90] = "Ninety "; cache[100] = "Hundred "; cache[-1] = "Thousand "; 
    cache[-2] = "Million "; cache[-3] = "Billion ";

    int flag = 0;
    while(num)
    {
        int tmp = num%1000;
        num /= 1000;
        string str = func(cache,tmp);
        if(flag == 0)
            result = str;
        else if(str.size() != 0)
            result = str + cache[flag] + result;
        --flag;
    }

    if(result.size() == 0)
        result = cache[0];

    result.pop_back();
    return result;
}

int main()
{
    string result = numberToWords(1000000);
    cout << result << endl;
    return 0;
}
