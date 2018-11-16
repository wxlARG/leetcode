#include"common.h"
using namespace std;

string reverseVowels(string s) { 
    unordered_set<char> vowels={'a', 'e' , 'i' ,'o' ,'u', 'A', 'E' , 'I' ,'O' ,'U'};
    for(int start=0, end=s.size()-1; start<end;) {
        while(start<end && !vowels.count(s[start])) ++start;
        while(start<end && !vowels.count(s[end])) --end;
        if(start<end) swap(s[start++], s[end--]);
    }
    return s;
}

int main() {
    cout << reverseVowels("hello") << endl;
    cout << reverseVowels("leetcode") << endl;
}
