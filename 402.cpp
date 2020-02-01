#include"common.h"
using namespace std;

string removeKdigits(string num, int k) {
	if(k==num.size()) return "0";
	string res=num.substr(0, num.size()-k);
	int pos=0;
	while(pos<res.size()-1 && res[pos]<=res[pos+1]) ++pos;
	for(int i=num.size()-k; i<num.size(); ++i) {
		if(pos==res.size()-1 && res[pos]<=num[i]) continue;
		res.erase(pos, 1);
		res.push_back(num[i]);
		if(pos>0 && res[pos-1]>res[pos]) --pos;
		else while(pos<res.size()-1 && res[pos]<=res[pos+1]) ++pos;
	}
	for(pos=0; pos<res.size() && res[pos]=='0'; ++pos);
	return pos==res.size()? "0": res.substr(pos);
}

int main() {
	cout << removeKdigits("1432219", 3) << endl;
}
