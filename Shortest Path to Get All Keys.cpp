int shortestPathAllKeys(vector<string>& grid) 
{
	int n=grid.size();
	int m=grid[0].length();
	int allmask=0;
	vector<int> temp;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(grid[i][j]=='@')
				temp={i,j};
			else if(grid[i][j]>='a'&&grid[i][j]<='f')
				allmask=allmask|(1<<(grid[i][j]-'a'));
	temp.push_back(0);
	temp.push_back(0);
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	vector<vector<vector<int>>> grey(n,vector<vector<int>>(m,vector<int>(allmask+1,0)));	
	queue<vector<int>> q;
	q.push(temp);
	grey[temp[0]][temp[1]][0]=1;
	int ret=INT_MAX;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		int i=temp[0],j=temp[1],mask=temp[2],d=temp[3];
		if(mask==allmask)
			return d;/*ret=min(ret,d);*/
		else
			for(int k=0;k<4;++k)
			{
				int x=i+dx[k],y=j+dy[k];
				if(x>=0&&x<n&&y>=0&&y<m)
				{
					if(grid[x][y]>='a'&&grid[x][y]<='f'&&((mask&1<<(grid[x][y]-'a'))==0))
					{
						q.push({x,y,mask|1<<(grid[x][y]-'a'),d+1});
						grey[x][y][mask|1<<(grid[x][y]-'a')]=1;
					}
					else if(grey[x][y][mask]==0)
					{

						if(grid[x][y]>='A'&&grid[x][y]<='F'&&((mask&1<<(grid[x][y]-'A'))!=0))
						{
							q.push({x,y,mask,d+1});
							grey[x][y][mask]=1;
						}
						else if(grid[x][y]=='.'||grid[x][y]=='@'||(grid[x][y]>='a'&&grid[x][y]<='f'))
						{
							q.push({x,y,mask,d+1});
							grey[x][y][mask]=1;
						}
					}

				}
			}
	}
	return ret<INT_MAX?ret:-1;
}