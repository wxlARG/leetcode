#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include"common.h"
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    for(int end_pos=0; end_pos<int(words.size()); ) {
        int start_pos = end_pos;
        ++end_pos;
        string cache;
        int len=words[start_pos].size();
        while(end_pos<int(words.size()) && len+words[end_pos].size()+end_pos-start_pos<=maxWidth) {
            len += words[end_pos++].size();
        }
        if(start_pos==end_pos-1 || end_pos == words.size()) {
            for(int i=start_pos; i<end_pos; ++i) {
                cache += words[i] + (i==end_pos-1? "": " ");
            }
            cache += string(maxWidth-cache.size(), ' ');
        } else {
            int space = (maxWidth-len)/(end_pos-start_pos-1);
            int remainder = maxWidth-len-space*(end_pos-start_pos-1);
            for(int i=start_pos; i<end_pos; ++i) {
                cache += words[i];
                if(i!=end_pos-1) cache += string(space+(remainder-->0? 1: 0), ' ');
            }
        }
        res.push_back(cache);
    }
    return res;
}

int main() {
    //vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words = {"Here","is","an","example","of","text","justification."};
    //vector<string> words = {""};
    auto res = fullJustify(words, 14);
    for(auto v: res) {
        cout << v << endl;
    }
}
