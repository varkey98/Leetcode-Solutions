    vector<vector<int>> visited;
   void  aux(vector<vector<int>>& image, int sr, int sc, int newColor,int init) {
        if(sr>=image.size()||sc>=image[0].size())
            return ;
        if(visited[sr][sc]!=-1)
            return ;
        visited[sr][sc]=1;
        if(image[sr][sc]==init)
        {
            image[sr][sc]=newColor;
        aux(image,sr+1,sc,newColor,init);
       aux(image,sr-1,sc,newColor,init);
       aux(image,sr,sc+1,newColor,init);
       aux(image,sr,sc-1,newColor,init);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        visited.resize(image.size(),vector<int>(image[0].size(),-1));
        aux(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }