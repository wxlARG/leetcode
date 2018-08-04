#include"common.h"
using namespace std;

bool wordPattern_solution1(string pattern, string str) {
    string cache;
    int j=0;
    unordered_map<char, int> mapping1;
    unordered_map<string, int> mapping2;
    for(int i=0; i<str.size() && j<pattern.size(); ++i) {
        if(str[i]==' ') {
            if(mapping1.find(pattern[j])==mapping1.end() && mapping2.find(cache)==mapping2.end()) {
                mapping1[pattern[j]]=mapping2[cache]=j;
            } else if(mapping1.find(pattern[j])==mapping1.end() || mapping2.find(cache)==mapping2.end()) {
                return false;
            } else if(mapping1[pattern[j]]!=mapping2[cache]) {
                return false;
            }
            cache.clear();
            ++j;
        } else {
            cache+=str[i];
        }
    }
    if(j==pattern.size() || j!=pattern.size()-1) return false;
    if(mapping1.find(pattern[j])==mapping1.end() && mapping2.find(cache)==mapping2.end()) return true;
    if(mapping1.find(pattern[j])!=mapping1.end() && mapping2.find(cache)!=mapping2.end() && mapping1[pattern[j]]==mapping2[cache]) return true;
    return false;
}

bool wordPattern(string pattern, string str) {
    string cache;
    int j=0;
    unordered_map<char, int> mapping1;
    unordered_map<string, int> mapping2;
    for(int i=0; i<str.size() && j<pattern.size(); ++i) {
        if(str[i]==' ') {
            if(mapping1[pattern[j]]!=mapping2[cache]) return false;
            mapping1[pattern[j]]=mapping2[cache]=j+1;
            cache.clear();
            ++j;
        } else {
            cache+=str[i];
        }
    }
    return j==pattern.size()-1 && mapping1[pattern[j]]==mapping2[cache];
}

int main() {
    cout << wordPattern("abba", "dog cat cat dog") << endl;
    cout << wordPattern("abba", "dog cat cat fish") << endl;
    cout << wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << wordPattern("aaaa", "dog dog dog dog") << endl;
    cout << wordPattern("abba", "dog dog dog dog") << endl;
}
