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

bool canWinNim(int n)
{
    if(n%4==0)
        return 0;
    return 1;
}

int main()
{
    bool result = canWinNim(4);
    cout << result << endl;
	return 0;
}
