#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_map>
using namespace std;

struct node
{
	int key;
	int val;
	node* prev;
	node* next;
	node(int key, int val):key(key),val(val),prev(NULL),next(NULL){};
};

class LRUCache{
	public:
		LRUCache(int capacity) {
			this->capacity=capacity;
			head = NULL;
		}

		int get(int key) {
			unordered_map<int, node*>::iterator iter = hashmap.find(key);
			if(iter!=hashmap.end())
			{
				node* ptr = iter->second;
				if(ptr->prev != NULL)
					ptr->prev->next = ptr->next;
				else
					head = ptr->next;

				if(ptr->next != NULL)
					ptr->next->prev = ptr->prev;
				else
					tail = ptr->prev;

				ptr->next = head;
				ptr->prev = NULL;
				if(head == NULL)
					tail = ptr;
				else
					head->prev = ptr;
				head = ptr;

				return ptr->val;
			}
			else
				return -1;
		}

		void set(int key, int value) {
			unordered_map<int, node*>::iterator iter = hashmap.find(key);
			if(iter != hashmap.end())
			{
/*				node* ptr = iter->second;
				if(ptr->prev != NULL)
					ptr->prev->next = ptr->next;
				else
					head = ptr->next;

				if(ptr->next != NULL)
					ptr->next->prev = ptr->prev;
				else
					tail = ptr->prev;

				hashmap.erase(key);
				delete ptr;*/

				get(key);
				iter = hashmap.find(key);
				iter->second->val=value;
				return;
			}

			if(hashmap.size()==capacity)
			{
				node* delnode = tail;
				tail = tail->prev;
				if(tail != NULL)
					tail->next = NULL;
				hashmap.erase(delnode->key);
				delete delnode;
			}

			node* newnode = new node(key, value);
			hashmap.insert(make_pair(key,newnode));
			newnode->next = head;
			if(head == NULL)
				tail = newnode;
			else
				head->prev = newnode;
			head = newnode;
		}
	private:
		int capacity;
		unordered_map<int, node*> hashmap;
		node* head;
		node* tail;
};

int main()
{
	LRUCache test(2);
	test.set(2,6);
	test.set(1,5);
	test.set(1,2);
	int result = test.get(2);
	cout << result << endl;
	return 0;
}
