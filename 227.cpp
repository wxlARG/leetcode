#include"common.h"
using namespace std;

void calc(stack<int>& nums, stack<char>& symbols) {
    char symbol=symbols.top();
    symbols.pop();
    int val=nums.top();
    nums.pop();
    if(symbol=='+') nums.top()+=val;
    else if(symbol=='-') nums.top()-=val;
    else if(symbol=='*') nums.top()*=val;
    else nums.top()/=val;
}

int calculate(string s) {
    stack<int> nums;
    stack<char> symbols;
    for(int i=0; i<s.size(); ) {
        if(s[i]==' ') {
            ++i;
        } else if(s[i]>='0' && s[i]<='9') {
            int num=0;
            for(; s[i]>='0' && s[i]<='9'; ++i) num = num*10+s[i]-'0';
            nums.push(num);
        } else {
            if(s[i]=='+' || s[i]=='-') {
                while(!symbols.empty()) calc(nums, symbols);
            } else {
                while(!symbols.empty() && (symbols.top()=='*' || symbols.top()=='/')) calc(nums, symbols);
            }
            symbols.push(s[i++]); 
        }
    }
    while(!symbols.empty()) calc(nums, symbols);
    return nums.top();
}

int main() {
    cout << calculate("3+2*2") << endl;
    cout << calculate("3/2") << endl;
    cout << calculate(" 3+5 / 2 ") << endl;
}
