int island=0;
vector<vector<int>> grey;
queue<pair<int,int>> q;
pair<int,int> t;
bool flag=true;
void dfs_visit(int i,int j,vector<vector<int>>& arr)
{
	grey[i][j]=1;
	arr[i][j]=island;
	int ret=0;
	if(i+1<arr.size()&&!grey[i+1][j]&&arr[i+1][j])
	{
		++ret;
		dfs_visit(i+1,j,arr);
	}
	if(j+1<arr.size()&&!grey[i][j+1]&&arr[i][j+1])
	{
		++ret;
		dfs_visit(i,j+1,arr);
	}
	if(i>0&&!grey[i-1][j]&&arr[i-1][j])
	{
		++ret;
		dfs_visit(i-1,j,arr);
	}
	if(j>0&&!grey[i][j-1]&&arr[i][j-1])
	{
		++ret;
		dfs_visit(i,j-1,arr);
	}
	if(ret<4&&flag)
	{
		t.first=i;
		t.second=j;
		q.push(t);
	}
}
void dfs(vector<vector<int>>& arr)
{
	for(int i=0;i<arr.size();++i)
		for(int j=0;j<arr.size();++j)
			if(arr[i][j]&&!grey[i][j])
			{
				++island;
				dfs_visit(i,j,arr);
				flag=false;
			}
}

int shortestBridge(vector<vector<int>>& arr) 
{
	int n=arr.size();
	grey.resize(n,vector<int>(n,0));
	dfs(arr);
	//grey.resize(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            grey[i][j]=0;
	int level=0;

	while(!q.empty())
	{
		int k=q.size();
		++level;
		for(int z=0;z<k;++z)
		{
			t=q.front();
			q.pop();
			int i=t.first;
			int j=t.second;
			grey[i][j]=1;
            //cout<<level<<" "<<i<<" "<<j<<endl;
			if(i+1<n&&!grey[i+1][j]&&arr[i+1][j]!=arr[i][j])
			{
				if(arr[i+1][j]==2)
				{
					flag=true;
					break;
				}
				arr[i+1][j]=arr[i][j];
				t.first=i+1;
				t.second=j;
				q.push(t);
                grey[i+1][j]=-1;
			}
			if(j+1<n&&!grey[i][j+1]&&arr[i][j+1]!=arr[i][j])
			{
				if(arr[i][j+1]!=0)
				{
					flag=true;
					break;
				}
				arr[i][j+1]=arr[i][j];
				t.first=i;
				t.second=j+1;
				q.push(t);
                grey[i][j+1]=-1;
			}
			if(i>0&&!grey[i-1][j]&&arr[i-1][j]!=arr[i][j])
			{
				if(arr[i-1][j]==2)
				{
					flag=true;
					break;
				}
				arr[i-1][j]=arr[i][j];
				t.first=i-1;
				t.second=j;
				q.push(t);
                grey[i-1][j]=-1;
			}
			if(j>0&&!grey[i][j-1]&&arr[i][j-1]!=arr[i][j])
			{
				if(arr[i][j-1]==2)
				{
					flag=true;
					break;
				}
				arr[i][j-1]=arr[i][j];
				t.first=i;
				t.second=j-1;
				q.push(t);
                grey[i][j-1]=-1;
			}
		}
		if(flag)
			break;
			
	}
	return level-1;
}		