int[] dr = {-1, 1, 0, 0};// working java solution
int[] dc = {0, 0, -1, 1};
public int bfs(int i,int j,int n,int m,List<List<Integer>> forest)
{
    int l=forest.size(),w=forest.get(0).size();
    int[][] grey= new int[l][w];
    grey[i][j]=1;
    Queue<int[]> q=new LinkedList<int[]>();
    int [] temp={i,j,0};
    q.add(temp);
    while(!q.isEmpty())
    {
        temp=q.poll();
        i=temp[0];j=temp[1];
        int d=temp[2];
        if(i==n&&j==m)
            return d;
        for(int di=0;di<4;++di)
        {
            int x=i+dr[di],y=j+dc[di];
            if(x<l&&x>=0&&y<w&&y>=0&&grey[x][y]==0&&forest.get(x).get(y)!=0) 
            {
                grey[x][y]=1;
                temp=new int[]{x,y,d+1};
                q.add(temp);
            }
        }

    }
    return -1;
}
public int cutOffTree(List<List<Integer>> forest) 
{
    List<int[]> trees = new ArrayList();
    for (int r = 0; r < forest.size(); ++r) 
        for (int c = 0; c < forest.get(0).size(); ++c) 
        {
            int v = forest.get(r).get(c);
            if (v > 1) trees.add(new int[]{v, r, c});
        }
    Collections.sort(trees, (a, b) -> Integer.compare(a[0], b[0]));
    int ans = 0, sr = 0, sc = 0;
    for (int[] tree: trees) 
    {
        int d = bfs( sr, sc, tree[1], tree[2],forest);
        if (d < 0) return -1;
        ans += d;
        sr = tree[1]; sc = tree[2];
    }
    return ans;
}