class Solution
{
public:
	void solve(int i, string& s, string& str, unordered_set<string>& set) {
		if(i==s.size()) {
			set.insert(str); 
			return;
		}
		
		if(s[i]=='?') {
			str+='1';
			solve(i+1,s,str,set);
			str.pop_back();
			str+='0';
			solve(i+1,s,str,set);
			str.pop_back();
		}
		else {
			str+=s[i];
			solve(i+1,s,str,set);
			str.pop_back();
        }
	}

	unordered_set<string> findCombinations(string s)
	{
		unordered_set<string> set;
		if(s=="") return set;
		
		string str="";
		solve(0,s,str,set);
		
		return set;
	}
};