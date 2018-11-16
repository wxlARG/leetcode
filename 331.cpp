#include"common.h"
using namespace std;

bool isValidSerialization(string preorder) {
    stack<int> s;
    int num=0, pos=0;
    for(; pos<preorder.size(); ++pos) {
        if(preorder[pos]==',') {
            if(preorder[pos-1]=='#') continue;
            s.push(num);
            num=0;
        } else if(preorder[pos]=='#') {
            if(s.empty()) break;
            s.pop();
        } else {
            num+=num*10+preorder[pos]-'0';
        }
    }
    return pos==preorder.size()-1 && s.empty();
}

int main() {
    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << isValidSerialization("1,#") << endl;
    cout << isValidSerialization("9,#,#,1") << endl;
}
