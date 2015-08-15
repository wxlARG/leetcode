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

bool isAnagram(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s==t;
}

int main()
{
	bool result = isAnagram("rat","car");
    cout << result << endl;
	return 0;
}
