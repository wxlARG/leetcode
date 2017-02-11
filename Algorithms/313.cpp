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

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    int64_t result = 1;
    int num = 1;

    vector<pair<int64_t, int>> minheap;
    make_heap(minheap.begin(),minheap.end(),greater<pair<int64_t, int>>());
    minheap.push_back(make_pair(1*primes[0],0));
    push_heap(minheap.begin(),minheap.end(),greater<pair<int64_t, int>>());

    while(num < n)
    {
        pop_heap(minheap.begin(),minheap.end(),greater<pair<int64_t, int>>());
        int64_t res = minheap.back().first;
        int pos = minheap.back().second;
        int64_t val = res / primes[pos];
        minheap.pop_back();

        if(res > result)
        {
            result = res;
            minheap.push_back(make_pair(result*primes[0],0));
            push_heap(minheap.begin(),minheap.end(),greater<pair<int64_t, int>>());
            ++num;
        }

        ++pos;
        if(pos == primes.size())
            continue;
        minheap.push_back(make_pair(val*primes[pos],pos));
        push_heap(minheap.begin(),minheap.end(),greater<pair<int64_t, int>>());
    }
    return result;
}

int main()
{
    vector<int> primes {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};

    int result = nthSuperUglyNumber(100000, primes);
    cout << result << endl;
    return 0;
}
