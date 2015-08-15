#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

void addnode(UndirectedGraphNode* node)
{
	if(node->neighbors.size()!=0 && node->neighbors.back()==NULL)
		return;

	UndirectedGraphNode* tmp = new UndirectedGraphNode(node->label);
	node->neighbors.push_back(tmp);
	node->neighbors.push_back(NULL);

	for(int i=0; i<node->neighbors.size()-2; ++i)
		addnode(node->neighbors[i]);
}

void copy(UndirectedGraphNode* node)
{
	UndirectedGraphNode* newnode = node->neighbors[node->neighbors.size()-2];
	if(newnode->neighbors.size() != 0)
		return;

	for(int i=0; i<node->neighbors.size()-2; ++i)
	{
		UndirectedGraphNode* peernode = node->neighbors[i];
		newnode->neighbors.push_back(peernode->neighbors[peernode->neighbors.size()-2]);
	}

	for(int i=0; i<node->neighbors.size()-2; ++i)
		copy(node->neighbors[i]);
}

void del(UndirectedGraphNode* node)
{
	if(node->neighbors.back()!=NULL)
		return;

	node->neighbors.pop_back();
	node->neighbors.pop_back();

	for(int i=0; i<node->neighbors.size(); ++i)
		del(node->neighbors[i]);
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	if(node == NULL)
		return NULL;

	addnode(node);
	copy(node);
	UndirectedGraphNode* result = node->neighbors[node->neighbors.size()-2];
	del(node);
	return result;
}

int main()
{
	UndirectedGraphNode* node1 = new UndirectedGraphNode(-1);
	//UndirectedGraphNode* node2 = new UndirectedGraphNode(1);

	//node1->neighbors.push_back(node2);
	//node2->neighbors.push_back(node2);

	UndirectedGraphNode* node = cloneGraph(node1);
	cout << node->label << endl;
	for(int i=0; i<node->neighbors.size(); ++i)
		cout << node->neighbors[i]->label << "\t";
	cout << endl;
	return 0;
}
