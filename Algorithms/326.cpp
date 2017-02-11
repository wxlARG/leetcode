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

bool isPowerOfThree(int n)
{
    if(n==0) return 0;
    while(n!=1 && n%3==0)
        n /= 3;
    return n==1?1:0;
}

int main()
{
    bool result = isPowerOfThree(27);
    cout << result << endl;
    return 0;
}
