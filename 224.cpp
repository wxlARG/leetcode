#include"common.h"
using namespace std;

void calc(stack<int>& nums, stack<char>& symbols) {
    int val=nums.top(); 
    nums.pop();  
    if(symbols.top()=='+') nums.top()+=val;
    else nums.top()-=val;
    symbols.pop();  
}

int calculate(string s) {
    stack<int> nums;
    stack<char> symbols;
    for(int p=0; p<s.size(); ) {
        if(s[p]==' ') {
            ++p;
        } else if(s[p]>='0' && s[p]<='9') {
            int num=0;
            for(; s[p]>='0' && s[p]<='9'; ++p) num = num*10+s[p]-'0';
            nums.push(num);
        } else {
            if(s[p]=='(') {
                symbols.push(s[p]);
            } else if(s[p]=='+' || s[p]=='-') {
                while(!symbols.empty() && (symbols.top()=='+' || symbols.top()=='-')) calc(nums, symbols);
                symbols.push(s[p]);
            } else {
                while(symbols.top()!='(') calc(nums, symbols);
                symbols.pop();
            }
            ++p;
        }
    }
    while(!symbols.empty()) calc(nums, symbols);
    return nums.top();
}

int main() {
    cout << calculate("1 + 1") << endl;
    cout << calculate(" 2-1 + 2 ") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << calculate("0") << endl;
    cout << calculate("(1)") << endl;
}
