#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring_solution1(string s) {
    bool cache[256] = {0};
    int res = 0;
    int start = 0, end = 0;

    for(auto &c : s) {
        if(cache[c]) {
            res = max(res, end - start);
            while(s[start] != c)
                cache[s[start++]] = false;
            start++;
        } else {
            cache[c] = true;
        }
        end++;
    }
    res = max(res, end - start);
    return res;
}

int lengthOfLongestSubstring_solution2(string s) {
    vector<int> cache(256, -1);
    int res=0, start=0;
    for(int i=0; i<s.size(); ++i) {
        if(cache[s[i]]>=start) {
            res = max(res, i-start);
            start = cache[s[i]]+1;
        }
        cache[s[i]] = i;
    }
    res = max(res, int(s.size())-start);
    return res;
}

int lengthOfLongestSubstring(string s) {
    int res=0;
    vector<int> cache(128, 0);
    int counter=0, start=0, end=0;
    while(end<s.size()) {
        if(cache[s[end++]]++>0) ++counter;
        while(counter>0) {
            if(cache[s[start++]]-->1) --counter;
        }
        if(end-start>res) res=end-start;
    }
    return res;
}

int main() {
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    cout << lengthOfLongestSubstring("bbbb") << endl;
}
