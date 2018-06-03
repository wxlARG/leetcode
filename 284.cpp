#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stdlib.h>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        lastflag = false;
        if(Iterator::hasNext())
            peekval = Iterator::next();
        else
            lastflag = true;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return peekval;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int tmp = peekval;
        if(Iterator::hasNext())
            peekval = Iterator::next();
        else
            lastflag = true;
        return tmp;
    }

    bool hasNext() const {
        return !lastflag;
    }
private:
    int peekval;
    bool lastflag;
};

int main()
{
    return 0;
}
