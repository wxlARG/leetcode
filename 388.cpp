#include"common.h"
using namespace std;

int lengthLongestPath_solution1(string input) {
	int res=0, pos=0, cur_len=0;
	vector<int> s;
	while(pos<input.size()) {
		int end=input.find_first_of("\n", pos);
		if(end==string::npos) end=input.size();
		if(input.substr(pos, end-pos).find('.')==string::npos) {
            s.push_back(end-pos+1);
            cur_len+=end-pos+1;
		} else {
            res=max(res, cur_len+end-pos);
        }
		int space_num=0;
		for(pos=end+1; pos<input.size() && input[pos]=='\t'; ++pos) ++space_num; 
		while(space_num<s.size()) {
			cur_len-=s.back();
			s.pop_back();
		}
	}
	return res;
}

int lengthLongestPath(string input) {
    int res=0, pos=0;
    vector<int> lens;
    while(pos<input.size()) {
        bool is_file=false;
        int cur_len=0, index=0;
        for(; pos<input.size() && input[pos]!='\n'; ++pos) {
            if(input[pos]=='\t') ++index;
            else ++cur_len;
            if(input[pos]=='.') is_file=true;
        }
        while(index<lens.size()) lens.pop_back();
        lens.push_back((lens.empty()? 0: lens.back())+cur_len);
        if(is_file) res=max(res, lens.back()+int(lens.size())-1);
        if(pos<input.size() && input[pos]=='\n') ++pos;
    }
    return res;
}

int main() {
    cout << lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
}
