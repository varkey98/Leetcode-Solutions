for(int i=0;i<n;++i)
        {
            int left=i>0?arr[i-1]:INT_MAX;
            int right=i+1<n?arr[i+1]:INT_MAX;
            if(arr[i]>left&&arr[i]<=right)
                ret[i]=1+ret[i-1];
            else if(arr[i]>right&&arr[i]<=left)
                ret[i]=1+ret[i+1];
        }