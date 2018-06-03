#include"common.h"
using namespace std;

int evalRPN(vector<string>& tokens) {
    vector<int> stack;
    for(auto &token: tokens) {
        if(token=="+" || token=="-" || token=="*" || token=="/") {
            int first=stack.back();
            stack.pop_back();
            int second=stack.back();
            stack.pop_back();
            if(token=="+") stack.push_back(second+first);
            if(token=="-") stack.push_back(second-first);
            if(token=="*") stack.push_back(second*first);
            if(token=="/") stack.push_back(second/first);
        } else {
            stack.push_back(stoi(token));
        }
    }
    return stack.back();
}

int main() {
    //vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl;
}
