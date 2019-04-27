#include"common.h"
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger(): is_integer(false), val(0) {}

    // Constructor initializes a single integer.
    NestedInteger(int value): is_integer(true), val(value) {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return is_integer;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return val;
    }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
        is_integer = true;
        val = value;
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
        list.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return list;
    }

  private:
    vector<NestedInteger> list;
    bool is_integer;
    int val;
};

void helper_solution1(string& s, int& pos, NestedInteger& ni) {
    while(pos<s.size()) {
        if(s[pos]=='[') {
            NestedInteger tmp;
            helper_solution1(s, ++pos, tmp);
            ni.add(tmp);
        } else if(s[pos]==']') {
            ++pos;
            return;
        } else if(s[pos]==',') {
            ++pos;
        } else {
            int flag=1;
            if(s[pos]=='-') {
                ++pos;
                flag=-1;
            }
            int num=0;
            for(; pos<s.size() && s[pos]>='0' && s[pos]<='9'; ++pos) num = num*10+s[pos]-'0';
            ni.add(NestedInteger(num*flag));
        }
    }
    return;
}

NestedInteger deserialize_solution1(string s) {
    if(s.empty() || s[0]!='[') return NestedInteger(stoi(s));
    NestedInteger ni;
    int pos=1;
    helper_solution1(s, pos, ni);
    return ni;
}

int parse(string& s, int& pos) {
    int flag=1, num=0;
    if(s[pos]=='-') {
        flag=-1;
        ++pos;
    }
    for(;isdigit(s[pos]);++pos) num= num*10+s[pos]-'0';
    return flag*num;
}

NestedInteger helper(string& s, int& pos) {
    NestedInteger res;
    if(isdigit(s[pos]) || s[pos]=='-') {
        res.setInteger(parse(s, pos));
    } else {
        ++pos;
        while(s[pos]!=']') res.add(helper(s, pos));
        ++pos;
    }
    if(s[pos]==',') ++pos;
    return res;
}

NestedInteger deserialize(string s) {
    int pos = 0;
    return helper(s, pos);
}

int main() {
    auto ni = deserialize("[123,[456,[789]]]");
    cout << ni.getList()[0].getInteger() << endl;
}
