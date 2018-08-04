#include"common.h"
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(first.empty() || num<=first.top()) first.push(num);
        else second.push(num);
        if(second.size()>first.size()) {
            first.push(second.top());
            second.pop();
        } else if(first.size()>second.size()+1) {
            second.push(first.top());
            first.pop();
        }
    }
    
    double findMedian() {
        if(first.size()!=second.size()) return first.top();
        return (first.top()+second.top())/2.0;    
    }
private:
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> second;
};

int main() {
    MedianFinder obj;
    obj.addNum(1);
    obj.addNum(2);
    cout << obj.findMedian() << endl;
    obj.addNum(3);
    cout << obj.findMedian() << endl;
}
