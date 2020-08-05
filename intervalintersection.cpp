vector<vector<int>> ret;
void fun(int i,int j,vector<vector<int>>& a,vector<vector<int>>& b)
{
	if(i>=a.size()||j>=b.size())
		return;
	vector<int> v1=a[i];
	vector<int> v2=b[j];
	if(v1[1]<v2[0])
		fun(i+1,j,a,b);
	else if(v2[1]<v1[0])
		fun(i,j+1,a,b);
	else if(v2[0]<=v1[1]&&v1[0]<=v2[0])
    {
        vector<int> temp;
        temp.push_back(max(v1[0],v2[0]));
        temp.push_back(min(v1[1],v2[1]));
        ret.push_back(temp);
        if(v2[1]<v1[1])
            fun(i,j+1,a,b);
        else
            fun(i+1,j,a,b);
    }
    else if(v1[0]<=v2[1]&&v2[0]<=v1[0])
    {
        vector<int> temp;
        temp.push_back(max(v1[0],v2[0]));
        temp.push_back(min(v1[1],v2[1]));
        ret.push_back(temp);
        if(v1[1]<v2[1])
            fun(i+1,j,a,b);
        else
            fun(i,j+1,a,b);
    }
}
vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    fun(0,0,A,B);
    return ret;
}