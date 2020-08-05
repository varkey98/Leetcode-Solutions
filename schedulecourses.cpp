//BFS algorithm, time limit exceeded.
using namespace std;
#include<vector>
#include<queue>
#include<map>
//#include<priority_queue>
/*struct node
{
	int t;
	int n;
	unordered_set<int> v;
};
int scheduleCourse(vector<vector<int>>& courses)
{
	queue<node> q;
	for(int i=0;i<courses.size();++i)
	{
		node s;
		s.t=courses[i][0];
		s.n=1;
		s.v.insert(i);
		q.push(s);
	}
	int ret=INT_MIN;
	while(!q.empty())
	{
		node s=q.front();
		q.pop();
		bool flag=true;
		for(int i=0;i<courses.size();++i)
			if(s.t+courses[i][0]<=courses[i][1]&&s.v.find(i)==s.v.end())
			{
				flag=false;
				node a;
				a.t=s.t+courses[i][0];
				a.n=s.n+1;
				a.v=s.v;
				a.v.insert(i);
				q.push(a);
			}
		if(flag)
			ret=max(ret,s.n);
	}
	return ret;
}*/
//greedy algorithm, wont work. course which ends first is taken first.
/*struct node
{
	int t;
	int d;
};
struct compareCourse
{
	bool operator()(node const& c1,node const& c2)
	{
		return c1.d>c2.d;
	}
};
int scheduleCourse(vector<vector<int>>& c)
{
	priority_queue<node,vector<node>,compareCourse> q;
	for(int i=0;i<c.size();++i)
	{
		node s;
		s.t=c[i][0];
		s.d=c[i][1];
		q.push(s);
	}
	int n=0;
	int time=0;
	while(!q.empty())
	{
		node s=q.top();
		q.pop();
		if(time+s.t<=s.d)
		{
			time+=s.t;
			++n;
		}
	}
	return n;
}*/
// top-down DP algorithm
map<pair<int,int>,int> r;
int dp(int i,vector<vector<int>>& c,int t)
{
	pair<int,int> p;
	p.first=i;
	p.second=t;
	if(r.find(p)!=r.end())
		return r[p];
	int q=INT_MIN;
	for(int j=i+1;j<c.size();++j)
		if(t+c[j][0]<=c[j][1])
			q=max(q,1+dp(j,c,t+c[j][0]));
	if(q==INT_MIN)
		q=1;
	r[p]=q;
	return q;
}
int scheduleCourse(vector<vector<int>>& courses)
{
    int q=0;
    for(int i=0;i<courses.size();++i)
	    q=max(q,dp(i,courses,courses[i][0]));
    return q;
}