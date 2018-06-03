#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> cache = {
        {'I', 1}, {'V', 5},
        {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500},
        {'M', 1000}
    };
    int res = 0, pos=0;
    while(pos<s.size()) {
        char next = (pos==s.size()-1? pos: pos+1);
        if(cache[s[pos]] < cache[s[next]]) {
            res += cache[s[next]]-cache[s[pos]];
            pos += 2;
        } else {
            res += cache[s[pos]];
            pos += 1;
        }
    }
    return res;
}

int main() {
    cout << romanToInt("MMMCCCXXXIII") << endl;
}
