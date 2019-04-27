#include"common.h"
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val)!=0) return false;
        dict[val]=nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.count(val)==0) return false;
        if(dict[val]!=nums.size()-1) {
            dict[nums.back()]=dict[val];
            nums[dict[val]]=nums.back();
        }
        dict.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos=rand()%nums.size();
        return nums[pos];
    }
private:
    unordered_map<int, int> dict;
    vector<int> nums;
};

int main() {
	RandomizedSet randomSet;
    randomSet.insert(1);
    randomSet.remove(2);
    randomSet.insert(2);
    cout << randomSet.getRandom() << endl;
    randomSet.remove(1);
    randomSet.insert(2);
    cout << randomSet.getRandom() << endl;
}
