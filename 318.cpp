#include"common.h"
using namespace std;

int maxProduct(vector<string>& words) {
    vector<pair<int, int>> cache(words.size());
    for(int i=0; i<words.size(); ++i) {
        int val=0;
        for(auto &c: words[i]) val|=1<<(c-'a');
        cache[i]={val, words[i].size()};
    }
    int res=0;
    for(int i=0; i<words.size(); ++i) {
        for(int j=0; j<i; ++j) {
            if((cache[i].first & cache[j].first)==0) {
                res=max(res, cache[i].second*cache[j].second);
            }
        }
    }
    return res;
}

int main() {
    vector<string> words={"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << maxProduct(words) << endl;
}
