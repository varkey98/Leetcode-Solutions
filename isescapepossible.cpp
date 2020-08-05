#define size 1000000
typedef vector<int> state;
bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
{
	if(!blocked.size())
	return true;
	vector<vector<int>> grey(size,vector<int>(size,0));
	int n=target[0],m=target[i];
	int i=source[0],j=source[i];
	grey[i][j]=1;
	queue<state> q;
	q.push({i,j});
	while(!q.empty())
	{
		i=q.top.at(0);
		j=q.top.at(1);
		q.pop();
		if(i==n&&j==m)
			return true;
		else
		{
			if(i+1<size&&blocked[i+1][j]!=1&&!grey[i+1][j])
			{
				q.push(i+1,j);
				grey[i+1][j]=1;
			}
			if(j+1<size&&blocked[i][j+1]!=1&&!grey[i][j+1])
			{
				q.push({i,j+1});
				grey[i][j+1]=1;
			}
			if(i>0&&blocked[i-1][j]!=1&&!grey[i-1][j])
			{
				q.push({i-1,j});
				grey[i-1][j]=1;
			}
			if(j>0&&blocked[i][j-1]!=1&&!grey[i][j-1])
			{
				q.push({i,j-1});
				grey[i][j-1]=1;
			}
		}
	}
	return false;
}