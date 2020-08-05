int minSwapsCouples(vector<int>& row) {
    map<int,int> index;
    int ret=0;
    for(int start=0;start<row.size();start++)
        index[row[start]]=start;
    for(int start=0;start<row.size();start+=2)
    {
        if(row[start]%2==0)
            if(row[start+1]==row[start]+1)
                continue;
            else
            {
                index[row[start+1]]=index[row[start]+1];
                index[row[start]+1]=start+1; 
                int temp=row[start+1];
                row[start+1]=row[start]+1;
                row[index[temp]]=temp;
                ++ret;
            }
        else
            if(row[start+1]==row[start]-1)
                continue;
            else
            {
                index[row[start+1]]=index[row[start]-1];
                index[row[start]-1]=start+1;
                int temp=row[start+1];
                row[start+1]=row[start]-1;
                row[index[temp]]=temp;
                ++ret;
            }
    }
    return ret;
}