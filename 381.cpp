#include"common.h"
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag=false;
        if(dict.count(val)==0) flag=true;
        dict[val].insert(nums.size());
        nums.push_back(val);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element.  */
    bool remove(int val) {
        if(dict.count(val)==0) return false;
        if(nums.back()!=val) {
            auto it=dict[val].begin();
            nums[*it]=nums.back();
            dict[nums.back()].insert(*it);
            dict[nums.back()].erase(nums.size()-1);
            dict[val].erase(it);
        } else {
            dict[val].erase(nums.size()-1);
        }
        if(dict[val].empty()) dict.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos=rand()%nums.size();
        return nums[pos];
    }
private:
    unordered_map<int, unordered_set<int>> dict;
    vector<int> nums;
};

int main() {
	RandomizedCollection collection;
    collection.insert(1);
    collection.insert(1);
    collection.insert(2);
    cout << collection.getRandom() << endl;
    collection.remove(1);
    cout << collection.getRandom() << endl;
}
