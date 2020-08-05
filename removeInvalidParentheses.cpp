class Solution {//  java solution.
HashSet<String> ret;
int maxlength=0;
void fun(int i,String s,String t,int l,int r)
{
	if(i==s.length())
	{
		if(l==r)
		{
			if(t.length()>maxlength)
			{
				ret.clear();
				ret.add(t);
				maxlength=t.length();
			}
			else if(t.length()==maxlength)
				ret.add(t);
		}
	}
	else
	{
        if(s.charAt(i)=='('||s.charAt(i)==')')
            fun(i+1,s,t,l,r);
		if(s.charAt(i)=='(')
		{
            ++l;
            t+='(';
		}
		else if(s.charAt(i)==')')
		{
            ++r;
			if(r<=l)
				t+=')';
			else return;

		}
		else t+=s.charAt(i);
		fun(i+1,s,t,l,r);
	}

}
    public List<String> removeInvalidParentheses(String s) {
        ret=new HashSet<String>();
        String t=new String();
        fun(0,s,t,0,0);
        return new ArrayList<String>(ret);
    }
}
//cpp solution
//gives TLE
unordered_set<string> ret;
int maxlength=0;
set<string> arr;
void fun(int i,string s,string t,int l,int r)
{
	if(i==s.length())
	{
		if(l==r)
		{
			if(t.length()>maxlength)
			{
				ret.clear();
				ret.insert(t);
				maxlength=t.length();
			}
			else if(t.length()==maxlength)
				ret.insert(t);
		}
	}
	else
	{
        if(arr.find(t)!=arr.end())
            return;
        if(s[i]=='('||s[i]==')')
            fun(i+1,s,t,l,r);
		if(s[i]=='(')
		{
            ++l;
            t.push_back('(');
		}
		else if(s[i]==')')
		{
            ++r;
			if(r<=l)
				t.push_back(')');
			else return;

		}
		else t.push_back(s[i]);
		fun(i+1,s,t,l,r);
	}

}
vector<string> removeInvalidParentheses(string s) 
{
    stack<char> st;
    fun(0,s,"",0,0);
    vector<string> temp(ret.begin(),ret.end());
    return temp;
}
//BFS solution
bool check(string s)
{
	int count = 0;
        for (const char ch : s) {
            if (ch == '(') count++;
            if (ch == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
}
vector<string> removeInvalidParentheses(string s)
{
	queue<string> q;
	q.push(s);
	vector<string> ret;
    unordered_set<string> v;
	int flag=0;
	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;++i)
		{
			string a=q.front();
			q.pop();
			if(check(a))
			{
				ret.push_back(a);
				flag=1;
			}
			else if(!flag)
				for(int j=0;j<a.length();++j)
				{
                    string t=a;
					if(a[j]=='('||a[j]==')')
                        t.erase(j,1);
                    else continue;
                    if(v.find(t)==v.end())
                    {
					    q.push(t);
                        v.insert(t);
                    }
				}
		}
		if(flag)
			break;
	}
    return ret;
}