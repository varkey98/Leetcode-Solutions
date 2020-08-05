vector<vector<bool>> grey;// doesn't work
bool dfs(int i,int j,int t,vector<vector<int>>& grid)
{
	if(i<0||j<0||i>=grid.size()||j>=grid.size()||grey[i][j]||t<grid[i][j])
		return false;
	if(i==grid.size()-1&&j==grid.size()-1)
		return true;
	grey[i][j]=true;	
	return dfs(i+1,j,t,grid)||dfs(i,j+1,t,grid)||dfs(i-1,j,t,grid)||dfs(i,j-1,t,grid);
    
}
int swimInWater(vector<vector<int>>& grid) 
{
	int n=grid.size();
    int m=n*n-1;
    int p=grid[0][0],r=m,q;
    while(p<=r)
    {
        q=p+(r-p)/2;
        grey.resize(n,vector<bool>(n,false));
        if(dfs(0,0,q,grid))
        {
            grey.resize(n,vector<bool>(n,false));
            if(!dfs(0,0,q-1,grid))
                break;
            else
                r=q-1;
        }
        else p=q+1;
    }  
    return q;
}
//does work
boolean[][] grey;
boolean dfs(int i,int j,int t,int[][] grid)
{
	if(i<0||j<0||i>=grid.length||j>=grid.length||grey[i][j]||t<grid[i][j])
		return false;
	if(i==grid.length-1&&j==grid[0].length-1)
		return true;
	grey[i][j]=true;
	boolean val=dfs(i+1,j,t,grid)||dfs(i,j+1,t,grid)||dfs(i-1,j,t,grid)||dfs(i,j-1,t,grid);
	//grey[i][j]=0;
    return val;
}

public int swimInWater(int[][] grid) 
{
    int n=grid.length;
	int m=n*n-1;
	int p=grid[0][0],r=m,q=m;
	while(p<=r)
	{
	     q=p+(r-p)/2;
	    grey=new boolean[n][n];
	    if(dfs(0,0,q,grid))
	    {
	        grey=new boolean[n][n];
	        if(!dfs(0,0,q-1,grid))
	            break;
	        else
	            r=q-1;
	    }
	  else p=q+1;
	}
	return q;
}

//Dijkstra's algorithm
class comp
{
	public:
	bool operator()(vector<int> a, vector<int> b)
	{
		return a.at(0)>b.at(0);
	}
};
int swimInWater(vector<vector<int>>& grid)
{
	int n=grid.size();
	vector<vector<int>> grey(n,vector<int>(n,10000));
	priority_queue<vector<int>,vector<vector<int>>,comp> q;
    vector<vector<int>> visited(n,vector<int>(n,1));
	vector<int> t;
	t.push_back(grid[0][0]);
	t.push_back(0);
	t.push_back(0);
	q.push(t);
    visited[0][0]=0;
	while(!q.empty())
	{
		vector<int> t=q.top();
		q.pop();
		int time=t[0];
		int i=t[1];
		int j=t[2];
		grey[i][j]=time;
        if(i==n-1&&j==n-1)
            break;
		if(i+1<n&&visited[i+1][j])
		{
			t[0]=max(time,grid[i+1][j]);
			t[1]=i+1;
			t[2]=j;
			q.push(t);
            visited[i+1][j]=0;
		}
		if(j+1<n&&visited[i][j+1])
		{
			t[0]=max(time,grid[i][j+1]);
			t[1]=i;
			t[2]=j+1;
			q.push(t);
            visited[i][j+1]=0;
		}
		if(i>0&&visited[i-1][j])
		{
			t[0]=max(time,grid[i-1][j]);
			t[1]=i-1;
			t[2]=j;
			q.push(t);
            visited[i-1][j];
        }
		if(j>0&&visited[i][j-1])
		{
			t[0]=max(time,grid[i][j-1]);
			t[1]=i;
			t[2]=j-1;
			q.push(t);
            visited[i][j-1]=0;
		}

	}
	return grey[n-1][n-1];

}