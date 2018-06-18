#include"common.h"
using namespace std;

void calc(stack<int>& nums, stack<char>& symbols) {
    int val=nums.top(); 
    nums.pop();  
    if(symbols.top()=='+') nums.top()+=val;
    else nums.top()-=val;
    symbols.pop();  
}

int calculate_solution1(string s) {
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

int helper(string& s, int& pos) {
    vector<int> nums;
    int op=1;
    while(pos<s.size()) {
        if(s[pos]==' ') {
            ++pos;
        } else if(s[pos]>='0' && s[pos]<='9') {
            int num=0;
            for(; s[pos]>='0' && s[pos]<='9'; ++pos) num = num*10+s[pos]-'0';
            nums.push_back(op*num);
        } else if(s[pos]=='-') {
            op=-1;  
            ++pos;
        } else if(s[pos]=='+') {
            op=1;
            ++pos;
        } else if(s[pos]=='(') {
            ++pos;
            nums.push_back(op*helper(s, pos));
        } else {
            ++pos;
            break;
        }
    }
    return accumulate(nums.begin(), nums.end(), 0);
}

int calculate(string s) {
    int pos=0;
    return helper(s, pos);
}

int main() {
    cout << calculate("1 + 1") << endl;
    cout << calculate(" 2-1 + 2 ") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << calculate("0") << endl;
    cout << calculate("(1)") << endl;
}
