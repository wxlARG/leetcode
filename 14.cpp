#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string res;
    for(int pos=0, flag=1; flag && strs.size()!=0 && pos<strs[0].size(); ++pos) {
        int c = strs[0][pos];
        for(int i=1; i<strs.size(); ++i) {
            if(pos==strs[i].size() || strs[i][pos]!=c) {
                flag=0;
                break;
            }
        }
        if(flag==1)
            res += c;
    }
    return res;
}

int main() {
    vector<string> strs = {};
    cout << longestCommonPrefix(strs) << endl;
}
