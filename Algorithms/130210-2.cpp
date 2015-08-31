#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void createPath(vector<vector<string> >& result, vector<string>& tmp, unordered_map<string, vector<string> >& map, string cur, string start)
{
	tmp.push_back(cur);
	if(cur == start)
	{
		reverse(tmp.begin(), tmp.end());
		result.push_back(tmp);
		reverse(tmp.begin(), tmp.end());
	}
	else
	{
		vector<string>& cache = map[cur];
		for(int i=0; i<cache.size(); ++i)
			createPath(result,tmp,map,cache[i],start);
	}
	tmp.pop_back();
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
{
	dict.insert(start);
	dict.insert(end);
	vector<vector<string> > result;
	unordered_map<string, vector<string> > map;

	unordered_set<string> queue[2];
	unordered_set<string>* prev = &queue[0];
	unordered_set<string>* cur = &queue[1];

	prev->insert(start);

	while(prev->size() != 0)
	{
		bool flag = 0;
		for (unordered_set<string>::iterator iter = prev->begin(); iter != prev->end(); ++iter)  
			dict.erase(*iter);  

		for(unordered_set<string>::iterator iter=prev->begin(); iter!=prev->end(); ++iter)
		{
			string word = *iter;
			string origin = word;
			for(int i=0; i<word.size(); ++i)
			{
				char alpha = word[i];
				for(char j='a'; j<='z'; ++j)
				{
					if(j==alpha)
						continue;
					word[i] = j;
					if(word == end)
					{
						flag = 1;
						vector<string> tmp(1,end);
						createPath(result,tmp,map,origin,start);
					}
					else if(!flag && dict.find(word)!=dict.end())
					{
						if(map.find(word)==map.end())
							map[word] = vector<string>(1,origin);
						else
							map[word].push_back(origin);
						cur->insert(word);
					}
				}
				word[i]=alpha;
			}
		}
		prev->clear();
		swap(cur,prev);
		if(flag)
			break;
	}
	return result;
}

int main()
{
	//		string start("hit");
	//		string end("cog");
	//		string arr[] = {"hot","dot","dog","lot","log"};

	string start("red");
	string end("tax");
	string arr[] = {"ted","tex","red","tax","tad","den","rex","pee"};
	//string start("qa");
	//string end("sq");
	//string arr[] = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

	unordered_set<string> dict;
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]); ++i)
		dict.insert(arr[i]);

	vector<vector<string> > result = findLadders(start,end,dict);
	for(int i=0; i<result.size(); ++i)
	{
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
