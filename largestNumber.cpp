string compare1(string a,string b)
{
	if(a.length()>b.length()||a.compare(b)>0)
		return a;
	else return b;

}
map<int,string> memo;
string dp(vector<int>& cost,int target)
{
	string str="";
    if(target==0)
        return str;
    if(memo.find(target)!=memo.end())
        return memo[target];
	for(int i=0;i<9;++i)
		if(cost[i]<=target)
		{
			string temp=dp(cost,target-cost[i]);
            if(temp.compare("a")==0)
                continue;
			string val=to_string(i+1)+temp;
			str=compare1(str,val);
		}
    if(target!=0&&str.length()==0)
        return memo[target]="a";
	return memo[target]=str;
}
string largestNumber(vector<int>& cost, int target) 
{
    string ret=dp(cost,target);
    if(ret.compare("a")==0)
        return "0";
    return ret;
    
}