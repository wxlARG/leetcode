#include"common.h"
using namespace std;

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL) return NULL;
    unordered_map<int, UndirectedGraphNode*> cache;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    cache[node->label]=new UndirectedGraphNode(node->label);
    while(!q.empty()) {
        auto n=q.front();
        q.pop();
        for(auto &t: n->neighbors) {
            if(cache.find(t->label)==cache.end()) {
                cache[t->label]=new UndirectedGraphNode(t->label);
                q.push(t);
            }
            cache[n->label]->neighbors.push_back(cache[t->label]);
        }
    }
    return cache[node->label];
}

int main() {
    auto res=cloneGraph(createUndirectedGraphNode({"0","1", "2", "#", "1", "2", "#", "2", "2"}));
    cout << res->label << endl;
    for(auto &p: res->neighbors) cout << p->label << "\t";
    cout << endl;
}
