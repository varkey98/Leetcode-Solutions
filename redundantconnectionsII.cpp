int parent(vector<int>& p,int u)
{
    if(p[u]==-1)
        return u;
    else return parent(p,p[u]);
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> p(edges.size()+1,-1);
    vector<int> ret;
    int i=edges.size();
    for(i=0;i<edges.size();++i)
        if(p[edges[i][1]]==-1)
            p[edges[i][1]]=i;
    else break;
    if(i<edges.size())
    {
    ret=edges[i];
    vector<int> t=edges[p[edges[i][1]]];
    edges.erase(edges.begin()+i);
    edges.erase(edges.begin()+p[t[1]]);
    edges.push_back(t);
    edges.push_back(ret);
    }
    for(int i=0;i<edges.size()+1;++i)
        p[i]=-1;
    
    for(int i=0;i<edges.size();++i)
        if(parent(p,edges[i][0])!=parent(p,edges[i][1]))
        {
            p[edges[i][1]]=edges[i][0];
        }
        else if(parent(p,edges[i][0])==parent(p,edges[i][1])==-1)
            p[edges[i][1]]=edges[i][0];
    else
        ret=edges[i];
    return ret;
}