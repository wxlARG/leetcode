#include"common.h"
using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {return is_int;};

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {return val;};

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {return list;};
    NestedInteger(int v, vector<NestedInteger> arr) {
        if(arr.empty()) {
            val=v;
            is_int=true;
        } else {
            list=arr;
            is_int=false;
        }
    }
  private:
    int val;
    bool is_int;
    vector<NestedInteger> list;
};

class NestedIterator {
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {    
        st.push({nestedList, 0});
        dfs();
    }

    int next() {
        const auto& nestedList=st.top().first;
        auto& pos=st.top().second;
        int val=nestedList[pos++].getInteger();
        dfs();
        return val;
    }

    bool hasNext() {
        return !st.empty();
    }
  private:
    void dfs() {
        while(!st.empty()) {
            const auto& nestedList=st.top().first;
            auto& pos=st.top().second;
            if(pos>=nestedList.size()) st.pop();
            else if (!nestedList[pos].isInteger()) st.push({nestedList[pos++].getList(), 0});
            else break;
        }
    }
    stack<pair<const vector<NestedInteger>&, int>> st;
};

int main() {
    NestedInteger n1={1, {}}, n2={4, {}}, n3={6, {}};
    NestedInteger nn1={0, {n3}}, nn2={0, {n2, nn1}};
    vector<NestedInteger> nestedList={n1, nn2};
	NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next() << "\t";
    cout << endl;
}
