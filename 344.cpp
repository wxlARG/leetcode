#include"common.h"
using namespace std;

string reverseString(string s) {
    for(int start=0, end=s.size()-1; start<end; ++start, --end) {
        swap(s[start], s[end]);
    }
    return s;
}

int main() {
    cout << reverseString("hello") << endl;
    cout << reverseString("A man, a plan, a canal: Panama") << endl;
}
