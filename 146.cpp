#include"common.h"
using namespace std;

class LRUCache {
    public:
        LRUCache(int capacity) {
            size=capacity;
        }

        int get(int key) {
            if(cache.find(key)==cache.end()) return -1;
            auto it=cache[key];
            int value=it->second;
            queue.erase(it);
            queue.push_front({key, value});
            cache[key]=queue.begin();
            return value;
        }

        void put(int key, int value) {
            if(cache.find(key)!=cache.end()) {
                auto it=cache[key];
                queue.push_front({key, value});
                queue.erase(it);
                cache[key]=queue.begin();
                return;
            }
            queue.push_front({key, value});
            if(queue.size()>size) {
                auto it=queue.back();
                queue.pop_back();
                cache.erase(it.first);
            }
            cache[key]=queue.begin();
        }
    private:
        list<pair<int, int>> queue;
        unordered_map<int, list<pair<int, int>>::iterator> cache;
        int size;
};

int main() {
    LRUCache obj = LRUCache(1);
    obj.put(2, 1);
    cout << obj.get(2) << endl;
    obj.put(3, 2);
    cout << obj.get(2) << endl;
    cout << obj.get(3) << endl;
}
