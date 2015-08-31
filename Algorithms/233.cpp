#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

int countDigitOne(int n)
{
    if(n<=0)
        return 0;

    string cache;
    int p=0;

    int n1 = n;
    while(n1!=0)
    {
        cache.push_back(n1%10);
        n1/=10;
        if(p==0)
            p=1;
        else
            p*=10;
    }

    int count = 0;
    int result = 0;
    for(int i=cache.size()-1; i>=0; --i)
    {
        count = count*10+cache[i];
        int loop = count/10;
        if(cache[i] > 1)
            result += (loop+1)*p;
        else if(cache[i] == 1)
            result += loop*p+n-count*p+1;
        else 
            result += loop*p;

        p/=10;
    }

    return result;
}

int main()
{
    int result = countDigitOne(1410065408);
    cout << result << endl;
	return 0;
}
