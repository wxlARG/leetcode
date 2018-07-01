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

int calculate_solution1(string s) {
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

int calculate(string s) {
    vector<int> nums;
    int flag=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]==' ') {
        } else if(s[i]>='0' && s[i]<='9') {
            int num=0;
            for(; s[i]>='0' && s[i]<='9'; ++i) num = num*10+s[i]-'0';
            if(flag==0) nums.push_back(num);
            else if(flag==1) nums.push_back(0-num);
            else if(flag==2) nums.back()*=num;
            else nums.back()/=num;
            --i;
        } else {
            if(s[i]=='+') flag=0;
            else if(s[i]=='-') flag=1;
            else if(s[i]=='*') flag=2;
            else flag=3;
        }
    }
    return accumulate(nums.begin(), nums.end(), 0);
}

int main() {
    cout << calculate("3+2*2") << endl;
    cout << calculate("3/2") << endl;
    cout << calculate(" 3+5 / 2 ") << endl;
}
