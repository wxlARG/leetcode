#include<iostream>
#include<sstream>
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

string getHint(string secret, string guess)
{
    int a[10] = {0};
    int bulls=0, cows=0;
    for(int i=0; i<secret.size(); ++i)
        ++a[secret[i]-'0'];

    for(int i=0; i<guess.size(); ++i)
        if(a[guess[i]-'0'] != 0 && secret[i]==guess[i])
        {
            ++bulls;
            --a[guess[i]-'0'];
        }

    for(int i=0; i<guess.size(); ++i)
        if(a[guess[i]-'0'] != 0 && secret[i]!=guess[i])
        {
            ++cows;
            --a[guess[i]-'0'];
        }

    string result;
    string tmp;
    stringstream ss;
    ss<<bulls;
    ss>>tmp;
    result += tmp+"A";

    ss.clear();
    tmp.clear();
    ss<<cows;
    ss>>tmp;
    result += tmp+"B";
    return result;
}

int main()
{
    string result = getHint("1080","1888");
    cout << result << endl;
	return 0;
}
