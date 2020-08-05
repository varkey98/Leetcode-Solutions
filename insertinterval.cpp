vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& n) 
{
    bool flag=false;
    vector<vector<int>> ret;
    for(int i=0;i<intervals.size();++i)
        if(flag)
            ret.push_back(intervals[i]);
        else if(intervals[i][1]<n[0])
            ret.push_back(intervals[i]);
        else if(n[1]<intervals[i][0])
        {
            flag=true;
            ret.push_back(n);
            ret.push_back(intervals[i]);
        }
        else if(n[0]<intervals[i][0]&&n[1]<=intervals[i][1])
            n[1]=intervals[i][1];
        else if(n[0]>=intervals[i][0]&&n[1]<=intervals[i][1])
        {
            flag=true;
            ret.push_back(intervals[i]);
        }
        else if(intervals[i][0]<n[0]&&intervals[i][1]<n[1])
            n[0]=intervals[i][0];
    if(!intervals.size()||!flag)//! flag means the interval has updated but didnt gget added to the array, that means it is the last element.
        ret.push_back(n);
    return ret;
}