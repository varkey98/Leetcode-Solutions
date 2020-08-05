    int leftMostColumnWithOne(BinaryMatrix &bm) {
        //cout<<binaryMatrix.get(0,1);
        vector<int> r=bm.dimensions();
        int x=0,y=0;
                int ret=INT_MAX;
        /*stack<pair<int,int>> s;
        pair<int,int> c;
        c.first=x;
        c.second=y;
        s.push(c);
        while(!s.empty())
        {
            c=s.top();
            s.pop();
            x=c.first;
            y=c.second;
            if(y>=r[0]||x>=r[1])
                continue;
            if(bm.get(y,x)==1)
                break;
            else
            {
                c.first=x+1;
                s.push(c);
                c.first=x;
                c.second=y+1;
                s.push(c);
            }
        }*/
        for(;y<r[0];++y)
        {
            int start=0,end=r[1],mid;
            while(start<end)
            {
                mid=(start+end)/2;
                if(bm.get(y,mid)==1)
                {
                    if(ret>mid)
                        ret=mid;
                    end=mid;
                }
                else start=mid+1;
            }
        }
        if(ret<INT_MAX)
            return ret;
        else return -1;
    }