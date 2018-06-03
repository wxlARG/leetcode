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

void func(vector<vector<int>>& cache, vector<bool> &color, int cur, vector<pair<int,int>>& height, int &max, vector<int>& result)
{
    color[cur] = 1;
    pair<int,int> h(-1,-1);

    for(int i=0; i<cache[cur].size(); ++i)
    {
        if(color[cache[cur][i]])
            continue;
        func(cache, color, cache[cur][i], height, max, result);
        if(h.first == -1)
            h.first = cache[cur][i];
        else if(h.second == -1 || height[cache[cur][i]] > height[h.second])
            h.second = cache[cur][i];

        if(h.second != -1 && height[h.first] < height[h.second])
            swap(h.first, h.second);
    }

    if(h.first==-1)
        return;

    height[cur].second = h.first;
    int h1 = h.first!=-1 ? height[h.first].first+1 : 0;
    int h2 = h.second!=-1 ? height[h.second].first+1 : 0;
    height[cur].first = h1;

    if(h1+h2 > max)
    {
        result.clear();
        max = h1+h2;
        int tmp = cur;
        while(h2<h1-1)
        {
            tmp = height[tmp].second;
            ++h2;
            --h1;
        }
        result.push_back(tmp);
        if(h1!=h2)
            result.push_back(height[tmp].second);
    }
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
{
    int max = 0;
    vector<vector<int>> cache(n);
    vector<pair<int,int>> height(n,make_pair(0,-1));
    vector<int> result;
    vector<bool> color(n,0);

    for(int i=0; i<edges.size(); ++i)
    {
        if(edges[i].first > edges[i].second)
            swap(edges[i].first, edges[i].second);
        cache[edges[i].first].push_back(edges[i].second);
    }

    func(cache, color, 0, height, max, result);
    if(result.empty() && n==1)
        result.push_back(0);
    return result;
}

int main()
{
//    int a[][2] = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    int a[][2] = {{1, 0}, {1, 2}, {1, 3}};
    vector<pair<int, int>> edges;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        edges.push_back(make_pair(a[i][0],a[i][1]));

    vector<int> result = findMinHeightTrees(6, edges);
    for(int i=0; i<result.size(); ++i)
        cout << result[i] << endl;
    return 0;
}
