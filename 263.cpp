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

bool isUgly(int num)
{
    if(num == 0)
        return 0;

    while(num % 5 == 0)
        num /= 5;

    while(num % 3 == 0)
        num /= 3;

    while(num % 2 == 0)
        num /= 2;

    if(num == 1)
        return 1;
    else
        return 0;
}

int main()
{
	bool result = isUgly(14);
    cout << result << endl;
	return 0;
}
