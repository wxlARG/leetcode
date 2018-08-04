#include"common.h"
using namespace std;

class Iterator {
	vector<int> data;
    int pos;
public:
	Iterator(const vector<int>& nums) {
        data=nums;
        pos=0;
    }
	Iterator(const Iterator& iter) {}
	virtual ~Iterator() {}
	// Returns the next element in the iteration.
	int next() {return data[pos++];}
	// Returns true if the iteration has more elements.
	bool hasNext() const {return pos<data.size()? true: false;};
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        more=true;
        if(Iterator::hasNext()) cur=Iterator::next();
        else more=false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cur;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int tmp=cur;
        if(Iterator::hasNext()) cur=Iterator::next();
        else more=false;
        return tmp;
	}

	bool hasNext() const {
	    return more;
	}

private:
    int cur;
    bool more;
};

int main() {
    vector<int> nums={1, 2, 3};
    PeekingIterator p(nums);
    cout << p.next() << endl;
    cout << p.peek() << endl;
    cout << p.next() << endl;
    cout << p.next() << endl;
    cout << p.hasNext() << endl;
}
