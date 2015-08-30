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

int addDigits(int num)
{
    if(num % 9 == 0)
        return num==0 ? 0 : 9;
    return num %9;
}

int main()
{
	int result = addDigits(38);
    cout << result << endl;
	return 0;
}
