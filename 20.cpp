#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;

bool isValid(string s) {
    string c;
    for(auto &v: s) {
        if(v == '(' || v == '[' || v== '{') {
            c.push_back(v);
        } else if(v == ')') {
            if(c.empty() || c.back() != '(') return false;
            else c.pop_back();
        } else if(v == ']') {
            if(c.empty() || c.back() != '[') return false;
            else c.pop_back();
        } else if(v == '}') {
            if(c.empty() || c.back() != '{') return false;
            else c.pop_back();
        }
    }
    return c.empty();
}

int main() {
    cout << isValid("[") << endl;
}
